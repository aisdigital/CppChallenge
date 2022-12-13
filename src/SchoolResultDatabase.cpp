#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "SchoolResultDatabase.h"

SchoolResultDatabase::SchoolResultDatabase() {}

void SchoolResultDatabase::loadDataFromCsvFile(const std::string &csvFilePath) {
    this->database.clear();

    std::ifstream csvFile(csvFilePath);
    if (!csvFile) {
        std::cout << "Specified CSV file \"" << csvFilePath << "\" not found" << std::endl;
        return;
    }
    
    std::string row;
    getline(csvFile, row);  // Discard CSV header row
    while (std::getline(csvFile, row)) {
        std::string token;
        std::vector<std::string> tokens;
        std::stringstream stream(row);
        
        while (getline(stream, token, ',')) {
            tokens.push_back(token);
        }
        
        SchoolResult record;
        record.dbn = tokens[0];
        record.schoolName = tokens[1];
        record.numberOfTestTakers = std::strtoul(tokens[2].c_str(), NULL, 10);
        record.criticalReadingMean = std::strtoul(tokens[3].c_str(), NULL, 10);
        record.mathematicsMean = std::strtoul(tokens[4].c_str(), NULL, 10);
        record.writingMean = std::strtoul(tokens[5].c_str(), NULL, 10);
        
        this->database.push_back(record);
    }
}
