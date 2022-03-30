// Challenge C++ AISDigital

#include <iostream>
#include "readcsvfile.h"
#include "readthread.h"
#include "csvfile.h"
#include "searchmenu.h"

int main(int argc, const char * argv[]) { 
  std::cout << "Challenge C++ - Claudio Toledo Filho" << std::endl;

  ReadCsvFile* readCsvFile = new ReadCsvFile();
  ReadThread* readThread = new ReadThread(readCsvFile);
  SearchMenu* searchMenu = new SearchMenu(); 

  readThread->run();
  
  searchMenu->showMenu();
}

