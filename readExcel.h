#ifndef READ_EXCEL_H
#define READ_EXCEL_H

#include "./generalStructs.h"
#include <iostream>
#include <map>
#include <fstream>
#include <filesystem>
#include <list>
#include <string>
#include <thread>


class ReadExcel
{
    private:
        std::list<std::string> listOfLinesFromFile;
        
    public:
        ReadExcel() = default;
        void readDataFromFile(const std::string &filePathInput);
        std::list<std::string> getListOfData();
        void getFileOnDir(std::map<int, std::string> &mapOfFiles);
};

#endif