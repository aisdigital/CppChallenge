#pragma once

#include <vector>
#include <string>
#include <sstream>

using CSVRow = std::vector<std::string>;
using CSVTable = std::vector<std::vector<std::string>>;

class CSVParser {
    public:
        CSVParser() = default;

        /// @brief Load CSV
        /// @param stream Populated string stream
        void loadCSV(std::stringstream& stream);

        /// @brief Gets CSV Table
        /// @return Return a constant reference to the table
        const CSVTable& getCSVTable() const;


        /// @brief Utility method to write CSV Files
        /// @param path Path to save the file
        /// @param table Populated table
        /// @return Status operation. 
        static bool writeCSVFile(const std::string& path, const CSVTable &table);

    private:
        CSVRow parseRow(const std::string &row) const;

        CSVTable data;

};