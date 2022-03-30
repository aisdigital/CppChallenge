#ifndef SAVECSVFILE_H
#define SAVECSVFILE_H

#include "savefileinterface.h"

#define OUTPUT_CSV_FILE_PATH "output/"
#define CSV_EXTENSION ".csv"

class SaveCsvFile : public SaveFileInterface {

public:
    SaveCsvFile();
    
    ~SaveCsvFile();

    bool save(vector<string> data, string name) override;

private:
    bool createOutputPath();

    bool folderExists(string folderName);
};

#endif // SAVEFILEINTERFACE_H