#include <fstream>
#include <iostream>
#include <filesystem>

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
            std::string targetName = this->interface.getUserInput("Enter your search for school name");
            std::vector<SatResult> results;
            if (this->database.searchBySchoolName(targetName, results)) {
                std::cout << results;
                if (this->interface.getUserConfirmation("Save the results to a file?")) {
                    std::string fileName = this->interface.getUserInput("Type the filename");
                    
                    if (!std::filesystem::create_directory("./output")) {
                        std::cout << "Failed to create \"output\" directory" << std::endl;
                    }

                    std::ofstream outFile("output/" + fileName);
                    if (!outFile) {
                        std::cout << "Error creating file \"" << fileName << "\" for output" << std::endl;
                    }
                    outFile << results;
                    outFile.close();
                }
            }
            break;
        }
        case Cli::MenuOption::SearchByDbn: {
            std::string targetDbn = this->interface.getUserInput("Enter your search for school DBN");
            SatResult result;
            if (this->database.searchByDbn(targetDbn, result)) {
                std::cout << result;
            }
            break;
        }
        case Cli::MenuOption::Invalid:  // Intentional fall through
        default:
            std::cout << "Invalid option!" << std::endl << std::endl;
            break;
        }

        this->interface.showMenu();
        selectedOption = this->interface.getUserMenuOption();
    }

    this->interface.close();
}