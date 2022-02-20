#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <map>
#include <mutex>
#include <string>

#include "dbnEntryStruct.h"

class FileHandler{
  public:
    FileHandler();
    ~FileHandler();

    void saveDataToFile( const std::map< std::string, DbnEntry >&, std::string );
    std::map< std::string, DbnEntry >& getData();

  private:
    void loadCsvData();

    static std::map< std::string, DbnEntry > data;
};

#endif

