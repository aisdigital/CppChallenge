#include <fstream>
#include <iostream>
#include <filesystem>

#include "App.h"

App::App(std::string inputFilePath) : inputFile{inputFilePath} { };

void App::run() {
    this->database.loadDataFromCsvFile(this->inputFile);
    
    this->interface.showMenu();
    Cli::MenuOption selectedOption = this->interface.getUserMenuOption();

    while (selectedOption != Cli::MenuOption::Exit) {
        switch (selectedOption) {
        case Cli::MenuOption::SearchByName: {
            std::string targetName = this->interface.getUserInput("Enter your search for school name");
            std::vector<SatResult> results;
            if (this->database.searchBySchoolName(targetName, results)) {
                std::cout << std::endl << results << std::endl;
                if (this->interface.getUserConfirmation("Save the results to a file?")) {
                    std::string fileName = this->interface.getUserInput("Type the filename");
                    std::filesystem::create_directory("./output");
                    std::ofstream outFile("output/" + fileName);
                    if (!outFile) {
                        std::cout << "Error creating file \"" << fileName << "\" for output" << std::endl;
                        break;
                    }
                    outFile << results;
                    outFile.close();
                    std::cout << "Successfully saved results to file" << std::endl;
                }
            }
            else {
                std::cout << std::endl << "No results found for searched name" << std::endl;
            }
            break;
        }
        case Cli::MenuOption::SearchByDbn: {
            std::string targetDbn = this->interface.getUserInput("Enter your search for school DBN");
            SatResult result;
            if (this->database.searchByDbn(targetDbn, result)) {
                std::cout << result;
            }
            else {
                std::cout << std::endl << "No results found for searched DBN" << std::endl;
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