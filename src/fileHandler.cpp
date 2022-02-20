#include "fileHandler.h"

#include <cstddef>
#include <fstream>
#include <iostream>

#include "csvParser.h"

#define CSV_FILE_PATH "input/SAT__College_Board__2010_School_Level_Results.csv"
#define CSV_HEADER "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean"

// Static member initialization
std::map< std::string, DbnEntry > FileHandler::data;

FileHandler::FileHandler(){
  loadCsvData();
}

FileHandler::~FileHandler(){
}

void FileHandler::saveDataToFile(
    const std::map< std::string, DbnEntry >& entries,
    std::string filename ){
  // TODO: method to create output directories
  std::ofstream csvFile( "output/" + filename );
  if( csvFile.is_open() == false ){
    std::cout << "\nFailed to write .csv file. Aborting..." << std::endl;
    abort();
  }
  csvFile << std::string( CSV_HEADER ) << std::endl;
  for( auto& entry : entries ){
    csvFile << CsvParser::parseStructToLine( entry.second ) << std::endl;
  }
  std::cout << "Output file successfully created" << std::endl;
}

std::map< std::string, DbnEntry >& FileHandler::getData(){
  return FileHandler::data;
}

void FileHandler::loadCsvData(){
  std::ifstream csvFile( CSV_FILE_PATH, std::ios::in );
  if( csvFile.is_open() == false ){
    std::cout << "\nFailed to read .csv file. Aborting..." << std::endl;
    abort();
  }

  DbnEntry entry;
  std::string line;
  std::getline( csvFile, line );
  // Don't try to parse header
  if( line.compare( std::string( CSV_HEADER ) ) != 0 ){
    entry = CsvParser::parseLineToStruct( line );
    data.insert( { entry.dbn, entry } );
  }
  while( true ){
    std::getline( csvFile, line );
    if( csvFile.eof() == true ) break;
    entry = CsvParser::parseLineToStruct( line );
    data.insert( { entry.dbn, entry } );
  }
}

