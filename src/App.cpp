#include "App.h"

App::App(std::string inputFilePath) : inputFile{inputFilePath} { };

void App::run() {
    this->database.loadDataFromCsvFile(this->inputFile);
    this->interface.open();
}