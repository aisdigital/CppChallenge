#ifndef CSVFILE_H
#define CSVFILE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * @brief Class that represents a csv file.
 */
class CsvFile {
public:
    /**
     * @brief Returns an instance of the singleton object
     * 
     * @return CsvFile*
     */
    static CsvFile* getInstance();

    /**
     * @brief Default setter
     * 
     * @param newCsvFile
     */
    void setCsvFile(vector<string> newCsvFile);

    /**
     * @brief Default getter
     * 
     * @return vector<string>
     */
    vector<string> getCsvFile();

private:
    /**
     * @brief Private constructor
     * 
     */
    CsvFile();

    /**
     * @brief Private destructor
     * 
     */
    ~CsvFile();

    static CsvFile* m_instance; /**< CsvFile singleton object*/
    vector<string> m_csvFile;  /**< Vector with data from csv file*/
};

#endif // CSVFILE_H