// Challenge C++ AISDigital

#include <iostream>

#include "FileUtils.hpp"
#include "SchoolSatResult.h"

int main(int argc, const char *argv[]) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  const std::vector<std::string> buffer = FileUtils::ReadCSV(inputfile);

  std::cout << "Challenge C++" << std::endl;
  std::cout << buffer[0] << std::endl;
  return 0;
}
