// Challenge C++ AISDigital

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "CsvReader.h"
#include "SatReader.h"
#include "SatResult.h"

std::unordered_map<std::string, std::shared_ptr<SatResult>> readResults() {
    std::unordered_map<std::string, std::shared_ptr<SatResult>> results;
    std::shared_ptr<SatResult> nextResult;

    SatReader reader;
    reader.startThread();

    do {
        nextResult = reader.getNext();

        if (nextResult != nullptr) {
            if (results.find(nextResult->Dbn) != results.end()) {
                // I made my code thinking that the DBN was unique as specified in the README of the challenge, so i just ignore te duplicated DBNs
                std::cout << "[WARNING] The DBN " + nextResult->Dbn + " appears multiple times on the CSV, only the value of the first line with this DBN will be considered." << std::endl;
                continue;
            }

            results[nextResult->Dbn] = nextResult;
        }
    } while (nextResult != nullptr);

    reader.join();

    // try {
    //     std::ifstream file("input/SAT__College_Board__2010_School_Level_Results.csv");
    //     std::string line;

    //     // Read header
    //     std::getline(file, line);
    //     CsvReader<SatResult> reader(line, columnSetters);

    //     while (std::getline(file, line)) {
    //         auto result = reader.readLine(line);
    //         results[result.Dbn] = result;
    //     }

    // } catch (std::exception& ex) {
    //     std::cout << "[Error] An error occurred while reading the CSV." << std::endl;
    //     std::cout << ex.what() << std::endl;
    //     exit(1);
    // }

    std::cout << results.size() << std::endl;

    // for (auto r : results) {
    //     std::cout << r.second->Dbn << ", " << r.second->SchoolName << ", " << r.second->NumberOfTestTakers << ", " << r.second->CriticalReadingMean << ", " << r.second->MathematicsMean << ", " << r.second->WritingMean << std::endl;
    // }

    return results;
}

int main(int argc, const char* argv[]) {
    readResults();
}
