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

    std::cout << "\n\n\tEnter the DBN:";

    std::cin >> dbn;

    const auto& found = results.find(dbn);

    if (found != results.end()) {
        std::cout << "\t\tResult found: " + found->second->toCsvLine() << std::endl;
    } else {
        std::cout << "\tNo results where found for the DBN " + dbn << std::endl;
    }
}

int main(int argc, const char* argv[]) {
    auto results = readResults();
    int userOption;

    do {
        userOption = getUserOption();

        switch (userOption) {
            case 1:
                /* code */
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
