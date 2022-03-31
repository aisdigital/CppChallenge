#ifndef READCSVFILE_H
#define READCSVFILE_H

#include "csvfile.h"
#include "readfileinterface.h"

#define CSV_FILE_PATH "input/SAT__College_Board__2010_School_Level_Results.csv"

/**
 * @brief Class responsible for reading the csv file.
 */
class ReadCsvFile : public ReadFileInterface{

public:
    /**
     * @brief Constructor
     */
    ReadCsvFile();

    /**
     * @brief Destructor
     */
    ~ReadCsvFile();

    /**
     * @brief Read data from csv file
     */
    void read() override;

private:
    CsvFile* m_csvFile; /**< CsvFile object*/
};

#endif // READCSVFILE_H