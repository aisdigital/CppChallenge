#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <cstddef>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "dbnEntryStruct.h"

class FileHandler{
  public:
    FileHandler();
    ~FileHandler();

    void saveDataToFile( std::vector< DbnEntry >, std::string );
    std::map< std::string, DbnEntry >& getData();

  private:
    void loadCsvData();

    static std::map< std::string, DbnEntry > data;
};

#endif

