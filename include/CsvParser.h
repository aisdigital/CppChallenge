#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "SatResult.h"

template <class T>
class CsvParser {
   public:
    // The constructor receives the CSV header with the column names separated by comma and a map from the expected columns name to the function that fills the equivalemt property on a object of type T
    CsvParser(std::string csvHeader, std::map<std::string, std::function<void(T*, std::string)>> columnSetters);

    // Parses the CSV into a object of type T
    T* parseLine(std::string csvLine);

   private:
    // Vector containing the column names names defined in the header
    std::vector<std::string> headerColumns;

    // <ap from the column name to the function that fills the equivalemt property on a object of type T
    std::map<std::string, std::function<void(T*, std::string)>> columnSetters;

    void setCsvHeader(std::string csvHeader);
    std::vector<std::string> extractHeaderColumns(std::string csvHeader);

    // Check if all the required headers are present and if there are duplicated headers on the CSV
    void validateHeaderColumns();
};

template class CsvParser<SatResult>;
