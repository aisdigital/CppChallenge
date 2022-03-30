#include "csvfile.h"

CsvFile* CsvFile::m_instance = nullptr;

CsvFile::CsvFile()
{

}

CsvFile::~CsvFile()
{

}

CsvFile* CsvFile::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new CsvFile();
    }
    return m_instance;
}

void CsvFile::deleteInstance()
{
    delete m_instance;
    m_instance = nullptr;
}

void CsvFile::setCsvFile(vector<string> newCsvFile)
{
    m_csvFile = newCsvFile;
}

vector<string> CsvFile::getCsvFile()
{
    return m_csvFile;
}