
#include "Parser.hpp"

#include <algorithm>
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
    std::cout << Parser::ToCSVString({schoolSatResult}) << std::endl;
  }

  static void Draw(const std::vector<SchoolSatResult> &schoolSatResultList) {
    std::cout << Parser::ToCSVString(schoolSatResultList) << std::endl;
  }

  static std::string ReadUserInput(const std::string &helperMsg) {
    std::string userInput;
    std::cout << ">> " + helperMsg + ": ";
    std::cin >> userInput;

    return userInput;
  }

  static void DrawAlertMsg(const std::string &message) {
    std::cout << ">> " << message << std::endl;
  }
};
