
#include "Parser.hpp"

#include <iostream>
#include <string>

class CLI {
public:
  static void DrawMenu() {
    std::cout << "\n      Challenge C++"
              << "\n╒═══════════════════════╕"
              << "\n│ (1) Search by Name    │"
              << "\n│ (2) Search by DBN     │"
              << "\n│ (q) Exit              │"
              << "\n╘═══════════════════════╛" << std::endl;
  }

  static void Draw(const SchoolSatResult &schoolSatResult) {
    std::cout << "DBN,School Name,Number of Test Takers,Critical Reading "
                 "Mean,Mathematics Mean,Writing Mean\n";
    std::cout << Parser::ToString(schoolSatResult) << std::endl;
  }

  static std::string ReadUserInput(const std::string &helperMsg) {
    std::string userInput;
    std::cout << ">> " + helperMsg + ": ";
    std::cin >> userInput;

    return userInput;
  }
};
