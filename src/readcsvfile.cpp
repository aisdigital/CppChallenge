#include "readcsvfile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::fstream;
using std::iostream;
using std::vector;
using std::string;

ReadCsvFile::ReadCsvFile()
{
    m_csvFile = CsvFile::getInstance();
}

ReadCsvFile::~ReadCsvFile()
{

}

void ReadCsvFile::read()
{
    fstream csvFileStream(CSV_FILE_PATH);
    vector<string> fileReaded;
    string line;

    while(getline(csvFileStream, line, '\n'))
    {
        fileReaded.push_back(line);
    }
    
    if(!fileReaded.empty())
    {
        m_csvFile->setCsvFile(fileReaded);
        std::cout << CSV_FILE_PATH << " is open!"  << std::endl;
    }
    else
    {
        std::cout << "Could not open " << CSV_FILE_PATH  << std::endl ;
    }
}