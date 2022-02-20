#ifndef CSV_PARSER
#define CSV_PARSER

#include <string>

#include "dbnEntryStruct.h"

class CsvParser{
  public:
    CsvParser() = delete;

    static DbnEntry parseLineToStruct( std::string );
    static std::string parseStructToLine( DbnEntry );

  private:
    static std::string getSubstring( std::string, std::size_t& );
};

#endif

