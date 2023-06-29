#pragma once

#include <vector>
#include <string>

using CSVRow = std::vector<std::string>;
using CSVTable = std::vector<std::vector<std::string>>;

class CSVParser {
    public:
        CSVParser() = default;

        /// @brief Load CSV file
        /// @param path File path
        /// @return Returns error status
        bool loadCSV(const std::string& path);

        /// @brief Gets CSV Table
        /// @return Return a constant reference to the table
        const CSVTable& getCSVTable() const;

        static bool writeCSVFile(const std::string& path, const CSVTable &table);

    private:
        CSVRow parseRow(const std::string &row) const;

        CSVTable table;

};