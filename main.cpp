// Challenge C++ AISDigital

#include <iostream>

#include "fileHandler.h"
#include "dbnEntryStruct.h"

int main(int argc, const char * argv[]) {
  std::cout << "Challenge C++" << std::endl;

  FileHandler handler;
  std::map< std::string, DbnEntry > data = handler.getData();


  // Routine to validate parsers
  std::vector< DbnEntry > entries;
  for( auto& mapEntry : data ){
    entries.insert( entries.end(), mapEntry.second );
  }
  handler.saveDataToFile( entries, "processed.csv" );

  return 0;
}

