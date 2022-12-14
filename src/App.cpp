#include <fstream>
#include <iostream>

#include "App.h"

App::App(std::string inputFilePath) : inputFile{inputFilePath} { };

void App::run() {
    this->database.loadDataFromCsvFile(this->inputFile);
    
    this->interface.open();
    
    this->interface.showMenu();
    Cli::MenuOption selectedOption = this->interface.getUserMenuOption();

    while (selectedOption != Cli::MenuOption::Exit) {
        switch (selectedOption) {
        case Cli::MenuOption::SearchByName: {
            std::string targetName = this->interface.getUserInput("Type your search");
            std::vector<SatResult> results;
            if (this->database.searchBySchoolName(targetName, results)) {
                std::cout << results;
                if (this->interface.getUserConfirmation("Save the results to a file?")) {
                    std::string fileName = this->interface.getUserInput("Type the filename");
                    std::ofstream outFile("output/" + fileName);
                    outFile << results;
                    outFile.close();
                }
            }
            break;
        }
        case Cli::MenuOption::SearchByDbn: {
            std::string targetDbn = this->interface.getUserInput("Type your search");
            SatResult result;
            if (this->database.searchByDbn(targetDbn, result)) {
                std::cout << result;
            }
            break;
        }
        default:
            break;
        }

        this->interface.showMenu();
        selectedOption = this->interface.getUserMenuOption();
    }

    this->interface.close();
}