#ifndef SAVECSVFILE_H
#define SAVECSVFILE_H

#include "savefileinterface.h"

#define OUTPUT_CSV_FILE_PATH "output/"
#define CSV_EXTENSION ".csv"

/**
 * @brief Class that responsible for saving data in new csv file
 */
class SaveCsvFile : public SaveFileInterface {

public:
    /**
     * @brief Constructor
     */
    SaveCsvFile();
    
    /**
     * @brief Destructor
     */
    ~SaveCsvFile();

    /**
     * @brief Save data in csv file
     * 
     * @param data
     * @param name
     */
    bool save(vector<string> data, string name) override;

private:
    /**
     * @brief Create output path to save new csv file
     */
    bool createOutputPath();

    /**
     * @brief Checks if output folder exists
     */
    bool folderExists(string folderName);
};

#endif // SAVEFILEINTERFACE_H