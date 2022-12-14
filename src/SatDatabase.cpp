#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "SatDatabase.h"

SatDatabase::SatDatabase() {}

void SatDatabase::loadDataFromCsvFile(const std::string &csvFilePath) {
    this->satData.clear();

    std::ifstream csvFile(csvFilePath);
    if (!csvFile) {
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
        
        SatResult result;
        result.schoolName = tokens[1];
        result.numberOfTestTakers = tokens[2];
        result.criticalReadingMean = tokens[3];
        result.mathematicsMean = tokens[4];
        result.writingMean = tokens[5];
        
        this->satData[tokens[0]] = result;
    }
}

bool SatDatabase::searchBySchoolName(std::string searchString, std::vector<SatResult> &results) {
    results.clear();
    std::transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);
    
    for (auto &item : this->satData) { 
        std::string schoolName = item.second.schoolName;
        std::transform(schoolName.begin(), schoolName.end(), schoolName.begin(), ::tolower);
        if (schoolName.find(searchString) != std::string::npos) {
            results.push_back(item.second);
        }
    }

    std::sort(results.begin(), results.end(), [](const SatResult &schoolA, const SatResult &schoolB) {
        return schoolA.schoolName < schoolB.schoolName;
    });
    
    return !results.empty();
}

bool SatDatabase::searchByDbn(std::string searchString, SatResult &result) {
    std::transform(searchString.begin(), searchString.end(), searchString.begin(), ::toupper);  // DBNs are all uppercase

    auto found = this->satData.find(searchString);
    if (found != this->satData.end()) {
        result = found->second;
        return true;
    }
    else {
        return false;
    }
}
