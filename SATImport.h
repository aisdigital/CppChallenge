#ifndef SAT_IMPORT_H
#define SAT_IMPORT_H

#include "./readExcel.h"
#include <list>
#include <thread>
#include <sstream>

class SATImport
{
    friend std::ostream &operator<<(std::ostream &out , const SATModel_st &dataToOutput);
    private:
        std::string filePath;
        std::list<SATModel_st> listOfData;

    public:
        SATImport() = default;
        ~SATImport() = default;
        void formatRawDataFromFile(const std::list<std::string> &aux);
        int filterData(int field, std::string keyword = "");

};


#endif