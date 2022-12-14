#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "SatResult.h"

class SatDatabase {
    std::unordered_map<std::string, SatResult> satData;

public:
    SatDatabase();
    void loadDataFromCsvFile(const std::string &csvFilePath);
    bool searchBySchoolName(std::string searchString, std::vector<SatResult> &results);
    bool searchByDbn(std::string searchString, SatResult &result);
};