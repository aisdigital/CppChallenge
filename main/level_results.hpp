#pragma once


#include <string>
#include <unordered_map>
#include "csv_parser.hpp"


class LevelResults {
public:
    LevelResults() = default;
    explicit LevelResults(const CSVTable& table);

    /// @brief Convert the CSV in table form to the internal hash table format
    /// @param table CSV in table format
    void processCSVTable(const CSVTable& table);


    /// @brief Search the level results by name 
    /// @param name Substring to search on the school names
    /// @return A CSV table with all the rows found or emply table if none are found
    CSVTable queryBySchoolName(const std::string& name) const;


    /// @brief Search the level results by dbn
    /// @param dbn DBN Value
    /// @return A row with the DBN or emply row if none are found
    CSVRow  queryByDBN(const std::string& dbn) const;

private:
    std::unordered_map<std::string, std::vector<std::string>> data; 

};