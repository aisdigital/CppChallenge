// Challenge C++ AISDigital

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "SatReader.h"
#include "SatResult.h"

std::unordered_map<std::string, std::shared_ptr<SatResult>> readResults();
int getUserOption();
void searchByDbn(std::unordered_map<std::string, std::shared_ptr<SatResult>> results);
void searchByName(std::unordered_map<std::string, std::shared_ptr<SatResult>> results);
void confirmSaveSearchResult(std::vector<std::shared_ptr<SatResult>> searchResults);

int main(int argc, const char* argv[]) {
    auto results = readResults();
    int userOption;

    do {
        userOption = getUserOption();

        switch (userOption) {
            case 1:
                searchByName(results);
                break;

            case 2:
                searchByDbn(results);
                break;

            case 3:
                std::cout << "\n\t\t*** Exiting ***\n"
                          << std::endl;
                break;

            default:
                std::cout << "\n\t\t*** INVALID OPTION ***\n"
                          << std::endl;
                break;
        }
    } while (userOption != 3);

    return 0;
}

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

    return results;
}

int getUserOption() {
    std::cout << "\n\n\tChoose an option:\n"
              << "\t\t1. Search by Name\n"
              << "\t\t2. Search by DBN\n"
              << "\t\t3. Exit\n"
              << "\n\tOption: ";

    int option = -1;
    std::cin >> option;

    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return option;
}

void searchByDbn(std::unordered_map<std::string, std::shared_ptr<SatResult>> results) {
    std::string dbn;

    std::cout << "\n\n\tEnter the DBN: ";

    std::cin >> dbn;

    const auto& found = results.find(dbn);

    if (found != results.end()) {
        std::cout << "\t\tResult found: " + found->second->toCsvLine() << std::endl;
    } else {
        std::cout << "\tNo results where found for the DBN " + dbn << std::endl;
    }
}

void searchByName(std::unordered_map<std::string, std::shared_ptr<SatResult>> results) {
    std::vector<std::shared_ptr<SatResult>> searchResults;
    std::string name;

    std::cout << "\n\n\tEnter the name: ";

    std::cin >> name;

    for (const auto& result : results) {
        if (result.second->SchoolName.find(name) != std::string::npos) {
            searchResults.push_back(result.second);
        }
    }

    if (searchResults.size() != 0) {
        std::sort(searchResults.begin(), searchResults.end(),
                  [](const std::shared_ptr<SatResult>& a, const std::shared_ptr<SatResult>& b) { return a->SchoolName < b->SchoolName; });

        std::cout << "\t\tResult found: " << std::endl;
        for (const auto& fr : searchResults) {
            std::cout << "\t\t\t" + fr->toCsvLine() << std::endl;
        }

        confirmSaveSearchResult(searchResults);

    } else {
        std::cout << "\tNo results where found for the name " + name << std::endl;
    }
}

void confirmSaveSearchResult(std::vector<std::shared_ptr<SatResult>> searchResults) {
    std::string input;

    do {
        std::cout << "\n\n\tDo you want to save the results? (y/n): ";
        std::cin >> input;
    } while (input != "y" && input != "n");

    if (input == "y") {
        const std::string csvExtension = ".csv";
        std::string filename;

        std::cout << "\n\n\tType the filename to save the result: ";
        std::cin >> filename;

        if (filename.size() == 0) {
            filename = "output.csv";
        }

        std::fstream outputFile("output/" + filename, std::ofstream::out | std::ofstream::trunc);

        if (!outputFile.is_open()) {
            std::cout << "[ERROR] Cannot open the file to save the results" << std::endl;
            return;
        }

        outputFile << "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean" << std::endl;

        for (const auto& result : searchResults) {
            outputFile << result->toCsvLine() << std::endl;
        }

        std::cout << "\tResults saved on output/" + filename << std::endl;
    }
}