// Challenge C++ AISDigital

#include <iostream>
#include "include/Controller.h"

int main(int argc, const char * argv[])
{
  std::cout << "Challenge C++" << std::endl;

  /*
    Test Example:
      [input]: 1
      [input]: school
      [input]: n
      [input]: 3
  */

  Controller cntrl("input/SAT__College_Board__2010_School_Level_Results.csv");
  cntrl.Run();

  return 0;
}
