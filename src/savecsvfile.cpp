#include "savecsvfile.h"

#include <fstream>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

using std::fstream;

SaveCsvFile::SaveCsvFile()
{

}

SaveCsvFile::~SaveCsvFile()
{

}

bool SaveCsvFile::save(vector<string> data, string name)
{
    std::fstream newFile;
    int lines = data.size();

    if(createOutputPath())
    {
        string outputPath = OUTPUT_CSV_FILE_PATH + name + CSV_EXTENSION;

        newFile.open(outputPath, std::ios::out | std::ios::app);

        for(int i = 0; i < lines; i++)
        {
            newFile << data[i] << "\n";
        }

        newFile.close();

        return true;
    }
    else
    {
        return false;
    }
}

bool SaveCsvFile::createOutputPath()
{
    if(!folderExists(OUTPUT_CSV_FILE_PATH))
    {
        int createResult = mkdir(OUTPUT_CSV_FILE_PATH, 0777);

        if(createResult == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

bool SaveCsvFile::folderExists(string folderName)
{
    struct stat st;
    stat(folderName.c_str(), &st);
    return st.st_mode & S_IFDIR;
}
