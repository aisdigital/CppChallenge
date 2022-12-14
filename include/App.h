#pragma once

#include <string>

#include "Cli.h"
#include "SatDatabase.h"

class App {
    Cli interface;
    SatDatabase database;
    std::string inputFile;
    std::string outputFile;

public:
    App(std::string inputFilePath);
    void run();
};