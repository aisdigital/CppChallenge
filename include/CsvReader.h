#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "SatResult.h"

template <class T>
class CsvReader {
   public:
    CsvReader(std::string csvHeader, std::map<std::string, std::function<void(T*, std::string)>> columnSetters);

    void setCsvHeader(std::string csvHeader);

    T* readLine(std::string csvLine);

   private:
    std::vector<std::string> headerColumns;
    std::map<std::string, std::function<void(T*, std::string)>> columnSetters;

    std::vector<std::string> extractHeaderColumns(std::string csvHeader);

    // Check if all the required headers are present and if there are duplicated headers on the CSV
    void validateHeaderColumns();
};

template class CsvReader<SatResult>;
