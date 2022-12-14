#include "App.h"

App::App(std::string inputFilePath) : inputFile{inputFilePath} { };

void App::run() {
    this->database.loadDataFromCsvFile(this->inputFile);
    
    this->interface.open();
    
    this->interface.showMenu();
    Cli::MenuOption selectedOption = this->interface.getUserOption();

    while (selectedOption != Cli::MenuOption::Exit) {
        switch (selectedOption) {
        case Cli::MenuOption::SearchByName: {
            std::string targetName = this->interface.getUserSearchText();

            break;
        }
        case Cli::MenuOption::SearchByDbn: {
            std::string targetDbn = this->interface.getUserSearchText();

            break;
        }
        default:
            break;
        }
    }

    this->interface.close();
}