#ifndef CLI_HEADER
#define CLI_HEADER

#include <string>
#include <map>

#include "fileHandler.h"
#include "dbnEntryStruct.h"

class Cli{
  public:
    Cli();
    ~Cli();

    void printMainMenu();
    void printSearchByDbnMenu();
    void printSearchByNameMenu();

  private:
    void formatAndPrintOutput( const std::map< std::string, DbnEntry >& entries );
    void saveSearchToFile( const std::map< std::string, DbnEntry >& );

    FileHandler handler;
    std::map< std::string, DbnEntry > data;
};

#endif

