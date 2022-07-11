// Challenge C++ AISDigital

#include <iostream>

#include "CLI.hpp"
#include "Database.hpp"
#include "SchoolSatResult.h"

int main(int argc, const char *argv[]) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  Database schoolSatResultsDB;
  schoolSatResultsDB.Read(inputfile);

  std::string menuOption = "q";

  do {
    CLI::DrawMenu();
    menuOption = CLI::ReadUserInput("Choose Option (1,2,q)");

    if (menuOption == "1") {
      const std::string schoolName = CLI::ReadUserInput("Type School Name");
      const auto schoolSatResultList =
          schoolSatResultsDB.FindBySchoolName(schoolName);

      if (schoolSatResultList.empty()) {
        CLI::DrawAlertMsg("Unable to find school '" + schoolName + "'");
      } else {
        CLI::Draw(schoolSatResultList);

        const std::string userInputWriteToFile =
            CLI::ReadUserInput("Write Output to a file? (y,[n])");

        if (userInputWriteToFile == "y") {
          const std::string filename =
              "output/" + CLI::ReadUserInput("Type File Name");

          const std::string buffer = Parser::ToCSVString(schoolSatResultList);
          FileUtils::Write(filename, buffer);

          CLI::DrawAlertMsg("Output exported to " + filename);
        }
      }
    } else if (menuOption == "2") {
      const std::string dbn = CLI::ReadUserInput("Type DBN");
      const auto schoolSatResultList = schoolSatResultsDB.FindByDBN(dbn);

      if (schoolSatResultList.empty()) {
        CLI::DrawAlertMsg("Unable to find school with DBN: '" + dbn + "'");
      } else {
        CLI::Draw(schoolSatResultList[0]);
      }
    } else if (menuOption == "q") {
      CLI::DrawAlertMsg("Exiting...");
    } else {
      CLI::DrawAlertMsg("Error! Invalid menu option '" + menuOption + "'");
    }
  } while (menuOption != "q");

  return 0;
}
