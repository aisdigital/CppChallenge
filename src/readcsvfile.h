#ifndef READCSVFILE_H
#define READCSVFILE_H

#include "fileinterface.h"
#include "csvfile.h"
#include "readfileinterface.h"

#define CSV_FILE_PATH "input/SAT__College_Board__2010_School_Level_Results.csv"

class ReadCsvFile : public ReadFileInterface{

public:
    ReadCsvFile();

    ~ReadCsvFile();

    void read() override;

private:
    CsvFile* m_csvFile;
};

#endif // READCSVFILE_H