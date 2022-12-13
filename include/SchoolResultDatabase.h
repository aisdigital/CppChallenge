#pragma once

#include <string>
#include <vector>

#include "SchoolResult.h"

class SchoolResultDatabase {
    std::vector<SchoolResult> database;

public:
    SchoolResultDatabase();
    void loadDataFromCsvFile(std::string csvFilePath);
};