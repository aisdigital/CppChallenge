#pragma once

#include <string>
#include <vector>

#include "SchoolResult.h"

class SchoolResultDatabase {
    std::vector<SchoolResult> database;

public:
    SchoolResultDatabase();
    void loadDataFromCsvFile(const std::string &csvFilePath);
    bool searchBySchoolName(std::string searchString, std::vector<SchoolResult> &selectedSchools);
};