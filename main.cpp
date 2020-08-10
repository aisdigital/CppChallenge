// Challenge C++ AISDigital

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "CsvReader.h"
#include "SatResult.h"

std::unordered_map<std::string, SatResult> readResults() {
    const std::map<std::string, std::function<void(SatResult&, std::string)>> columnSetters = {
        {"DBN", [](SatResult& result, std::string value) { result.Dbn = value; }},
        {"School Name", [](SatResult& result, std::string value) { result.SchoolName = value; }},
        {"Number of Test Takers", [](SatResult& result, std::string value) { result.NumberOfTestTakers = value; }},
        {"Critical Reading Mean", [](SatResult& result, std::string value) { result.CriticalReadingMean = value; }},
        {"Mathematics Mean", [](SatResult& result, std::string value) { result.MathematicsMean = value; }},
        {"Writing Mean", [](SatResult& result, std::string value) { result.WritingMean = value; }}};

    std::unordered_map<std::string, SatResult> results;

    try {
        std::ifstream file("input/SAT__College_Board__2010_School_Level_Results.csv");
        std::string line;

        // Read header
        std::getline(file, line);
        CsvReader<SatResult> reader(line, columnSetters);

        while (std::getline(file, line)) {
            auto result = reader.readLine(line);
            results[result.Dbn] = result;
        }

    } catch (std::exception& ex) {
        std::cout << "[Error] An error occurred while reading the CSV." << std::endl;
        std::cout << ex.what() << std::endl;
        exit(1);
    }

    return results;
}

int main(int argc, const char* argv[]) {
    readResults();
}
