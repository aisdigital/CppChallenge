#pragma once

#include <string>

#include "Cli.h"
#include "SatDatabase.h"

class App {
    Cli _interface;
    SatDatabase _database;
    std::string _inputFile;
    std::string _outputFile;

public:
    App(std::string inputFilePath, std::string outputFilePath);
    void run();
};