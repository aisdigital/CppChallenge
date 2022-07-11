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
      const SchoolSatResult schoolSatResult =
          schoolSatResultsDB.FindBySchoolName(schoolName);

      if (schoolSatResult.SchoolName != schoolName) {
        std::cout << "Unable to find school '" << schoolName << "'"
                  << std::endl;
      } else {
        const std::string userInputWriteToFile =
            CLI::ReadUserInput("Write Output to a file? (y,[n])");

        if (userInputWriteToFile == "y") {
          const std::string filename =
              "output/" + CLI::ReadUserInput("Type File Name");

          const std::string header =
              "DBN,School Name,Number of Test Takers,Critical Reading "
              "Mean,Mathematics Mean,Writing Mean";

          std::vector<std::string> buffer = {Parser::ToString(schoolSatResult)};

          FileUtils::WriteCSV(filename, header, buffer);
        } else {
          CLI::Draw(schoolSatResult);
        }

        CLI::Draw(schoolSatResult);
      }
    } else if (menuOption == "2") {
      const std::string dbn = CLI::ReadUserInput("Type DBN");
      const SchoolSatResult schoolSatResult = schoolSatResultsDB.FindByDBN(dbn);

      if (schoolSatResult.DBN != dbn) {
        std::cout << "Unable to find school with DBN: '" << dbn << "'"
                  << std::endl;
      } else {
        CLI::Draw(schoolSatResult);
      }
    } else if (menuOption == "q") {
      std::cout << ">> Exiting..." << std::endl;
    } else {
      std::cout << ">> Error! Invalid menu option '" << menuOption << "'"
                << std::endl;
    }
  } while (menuOption != "q");

  return 0;
}
