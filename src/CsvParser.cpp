#include "CsvParser.h"

#include <algorithm>
#include <iostream>
#include <sstream>

template <class T>
CsvParser<T>::CsvParser(std::string csvHeader, std::map<std::string, std::function<void(T*, std::string)>> columnSetters) {
    this->columnSetters = columnSetters;
    setCsvHeader(csvHeader);
}

template <class T>
void CsvParser<T>::setCsvHeader(std::string csvHeader) {
    extractHeaderColumns(csvHeader);
    validateHeaderColumns();
}

template <class T>
T* CsvParser<T>::parseLine(std::string csvLine) {
    int valueStart = 0;
    T* data = new T();

    for (int i = 0; i < headerColumns.size(); i++) {
        std::string value;

        // Skip white spaces at the beginning of the column
        while (valueStart < csvLine.size() - 1 && csvLine.at(valueStart) == ' ') {
            valueStart++;
        }

        auto isLastValue = i == (headerColumns.size() - 1);

        bool isValueInsideQuotes = false;
        if (valueStart < csvLine.size()) {
            isValueInsideQuotes = csvLine.at(valueStart) == '"';
        }

        if (isValueInsideQuotes) {
            valueStart += 1;  // Skip the quotes

            auto valueEnd = csvLine.find_first_of("\"", valueStart);

            if (valueEnd == std::string::npos) {
                std::cout << "[ERROR] The line (" + csvLine + ") has less values than expected. Expected: " + std::to_string(headerColumns.size()) << std::endl;
                exit(1);
            }

            value = csvLine.substr(valueStart, valueEnd - valueStart);

            // Move the valueStart to the next column
            if (!isLastValue) {
                while (valueStart < csvLine.size() - 1 && csvLine.at(valueStart) != ',') {
                    valueStart++;
                }
                valueStart++;  // Skip the ','
            }
        } else {
            int valueEnd;

            if (isLastValue) {
                valueEnd = csvLine.size();
            } else {
                valueEnd = csvLine.find_first_of(",", valueStart);

                if (valueEnd == std::string::npos) {
                    std::cout << "[ERROR] The line (" + csvLine + ") has less values than expected. Expected: " + std::to_string(headerColumns.size()) << std::endl;
                    exit(1);
                }
            }

            value = csvLine.substr(valueStart, valueEnd - valueStart);

            valueStart = valueEnd + 1;
        }

        const auto& setter = columnSetters.find(headerColumns[i]);
        setter->second(data, value);
    }

    return data;
}

template <class T>
std::vector<std::string> CsvParser<T>::extractHeaderColumns(std::string csvHeader) {
    std::stringstream ss(csvHeader);
    std::string column;

    while (std::getline(ss, column, ',')) {
        headerColumns.push_back(column);
    }

    return headerColumns;
}

template <class T>
void CsvParser<T>::validateHeaderColumns() {
    // Check if all the expected columns are in the CSV and if there aren't any duplicated column
    for (const auto& columnSetter : columnSetters) {
        const std::string& requiredColumn = columnSetter.first;
        int numberOfMatches = 0;

        for (const std::string& column : headerColumns) {
            if (requiredColumn == column) {
                numberOfMatches++;
            }
        }

        if (numberOfMatches == 0) {
            std::cout << "[ERROR] The required header column " + requiredColumn + " wasn't found on the CSV" << std::endl;
            exit(1);
        }

        if (numberOfMatches > 1) {
            std::cout << "[ERROR] The header column " + requiredColumn + " appear multiple times on the CSV." << std::endl;
            exit(1);
        }
    }

    // Check if the CSV has any column that we aren't expecting
    if (headerColumns.size() > columnSetters.size()) {
        for (const auto& column : headerColumns) {
            if (columnSetters.find(column) != columnSetters.end()) {
                std::cout << "[ERROR] Unexpected column: " + column << std::endl;
            }
        }
        exit(1);
    }
}
