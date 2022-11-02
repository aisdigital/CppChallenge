// Challenge C++ AISDigital

#include <iostream>
#include "school.h"

int main(int argc, const char * argv[]) { 
  std::cout << "Challenge C++" << std::endl;

  school* school1 = school::create("01M292,Henry Street School for International Studies ,31,391,425,385");
  school* school2 = school::create("01M509,CMSP HIGH SCHOOL ,,,,");
  school* school3 = school::create("01M539,\"New Explorations into Sci, Tech and Math HS \",47,568,583,568");

  cout << school1->to_string() << endl;
  cout << school2->to_string() << endl;
  cout << school3->to_string() << endl;

  return 0;
}

