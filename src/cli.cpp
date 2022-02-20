#include "cli.h"

#include <iomanip>
#include <iostream>
#include <map>

Cli::Cli(){
  data = handler.getData();
}

Cli::~Cli(){
}

void Cli::printMainMenu(){
  std::string option;
  do{
    std::cout << std::endl << "Select an option" << std::endl;
    std::cout << "1 - Search by School Name" << std::endl;
    std::cout << "2 - Search by DBN" << std::endl;
    std::cout << "3 - Exit" << std::endl << std::endl;
    std::cout << "Type your option (1, 2 or 3) and press [Enter]: ";
    std::cin >> option;

    switch( option[0] ){
      case '1':
        printSearchByNameMenu();
        break;
      case '2':
        printSearchByDbnMenu();
        break;
      case '3':
        std::cout << "Quitting the application!" << std::endl;
        break;
      default:
        std::cout << "Invalid operation requested!" << std::endl << std::endl;
    }
  } while( option[0] != '3' );
}

void Cli::printSearchByDbnMenu(){
  std::string dbnSearched;

  std::cout << std::endl;
  std::cout << "Type DBN you are searching for and press [ENTER]";
  std::cout << std::endl << "DBN: ";
  std::cin >> dbnSearched;

  auto iterator = data.find( dbnSearched );
  if( iterator != data.end() ){
    std::map< std::string, DbnEntry > entry;
    entry.insert( { iterator->first, iterator->second } );
    formatAndPrintOutput( entry );
  }
  else{
    std::cout << "No records found for DBN " + dbnSearched + "." << std::endl;
  }
}

void Cli::printSearchByNameMenu(){
  std::map< std::string, DbnEntry > entries; // New map with School Name as key
  std::string nameSearched;

  std::cout << std::endl;
  std::cout << "Type the school name you are searching for and press [ENTER]";
  std::cout << std::endl << "School: ";
  std::cin >> nameSearched;

  for( auto& entry : data ){
    // TODO: make comparison case-insensitive
    // BUG: std::map isn't a good choice here because School Names are not
    //      unique, and this causes collisions on the key, garbling the results.
    if( entry.second.schoolName.find( nameSearched ) != std::string::npos ){
      entries.insert( { entry.second.schoolName, entry.second } );
    }
  }
  if( entries.empty() == false ){
    formatAndPrintOutput( entries );
    saveSearchToFile( entries );
  }
  else{
    std::cout << "No records found for School " + nameSearched + "." << std::endl;
  }
}

void Cli::formatAndPrintOutput( const std::map< std::string, DbnEntry >& entries ){
  std::cout << std::left << std::setw( 8 ) << "DBN";
  std::cout << std::setw( 54 ) << "School Name";
  std::cout << std::setw( 22 ) << "Number of Test Takers";
  std::cout << std::setw( 22 ) << "Critical Reading Mean";
  std::cout << std::setw( 17 ) << "Mathematics Mean";
  std::cout << std::setw( 13 ) << "Writing Mean" << std::endl;

  for( auto& entry : entries ){
    std::cout << std::setw( 8 ) << entry.second.dbn;
    std::cout << std::setw( 54 ) << entry.second.schoolName;
    std::cout << std::setw( 24 ) << entry.second.testTakers;
    std::cout << std::setw( 24 ) << entry.second.criticalReadingMean;
    std::cout << std::setw( 19 ) << entry.second.mathsMean;
    std::cout << std::setw( 15 ) << entry.second.writingMean << std::endl;
  }
}

void Cli::saveSearchToFile( const std::map< std::string, DbnEntry >& entries ){
  std::string filename;
  std::string option;

  std::cout << std::endl << std::endl;
  std::cout << "Would you like to save your search results to a file?";
  std::cout << std::endl << "Y/N: ";
  std::cin >> option;

  // TODO: Make better input treatment
  if( option[0] == 'Y' || option[0] == 'y' ){
    std::cout << std::endl;
    std::cout << "Type the CSV file name and press [ENTER]: ";
    std::cin >> filename;
    handler.saveDataToFile( entries, filename );
  }
}

