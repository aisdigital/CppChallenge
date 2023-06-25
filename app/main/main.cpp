// Challenge C++ AISDigital

#include <iostream>
#include "Controller.hpp"

int main(int argc, const char * argv[]) { 
  if(argc < 2) {
      std::cerr << "Missing input: " << "\033[31m" << "CSV file path" << std::endl;
      exit(0);
  }
  Controller control(argv[1]);
  control.run();
  return 0;
}

