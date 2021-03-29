// Challenge C++ AISDigital

#include <iostream>
#include <string>

#include "SchoolData.h"
#include "CommandManager.h"

using namespace std;


int main(int argc, const char * argv[]) { 
	
  std::cout << "Challenge C++" << std::endl;

  CommandManager* manager = new CommandManager();
  manager->MainLoop();

  return 0;
}

