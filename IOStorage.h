#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Configuration.h"
#include "School.h"

using namespace std;

class IIOStorage
{
public:
    virtual int createDirectory(string directoryName) = 0;
    virtual vector<string> readFile(string filename) = 0;
    virtual int writeCSV(string filename, vector<School*> schools) = 0;
};

class IOStorage : public IIOStorage
{
public:
    IOStorage();
    ~IOStorage();
    int createDirectory(string directoryName);
    vector<string> readFile(string filename);
    int writeCSV(string filename, vector<School*> schools);
};

IOStorage::IOStorage() {}

IOStorage::~IOStorage() {}

vector<string> IOStorage::readFile(string filename)
{
    vector<string> data;
    ifstream fileCsv(filename);
    string buffer;

    while (getline(fileCsv, buffer))
    {
        data.push_back(buffer);
    }

    fileCsv.close();

    return data;
}

int IOStorage::writeCSV(string filename, vector<School*> schools)
{
    try
    {
        ofstream file;

        file.open(filename, ofstream::trunc);

        if (file.fail())
        {
            cout << "File not opened" << endl;
            return -1;
        }

        for(School* school : schools)
        {
            file << school->toCSV() << endl;
        }

        file.close();

        return 0;
    }
    catch(exception e)
    {
        cout << "Unable to write the file. Please check filename" << endl;
        return -1;
    }
}

int IOStorage::createDirectory(string directoryName)
{
    stringstream ss;
    
    ss << "mkdir";

    #ifndef _WIN32
    ss << " -p ";
    #endif

    ss << directoryName;

    return system(ss.str().c_str());
}

#endif