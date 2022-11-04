#ifndef __CHALLENGE_H__
#define __CHALLENGE_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Configuration.h"
#include "Constant.h"
#include "IOStorage.h"
#include "School.h"
#include "helper/string.h"

#define SKIP_CSV_HEADER 1

using namespace std;

class Challenge
{
private:
    IIOStorage* _ioStorage = nullptr;
    vector<School*> _schools;
    unordered_map<string, School*> _schoolsFastLookup;
    int printMenu();
    void searchByName();
    void searchByDBN();
    void buildSchoolList(vector<School*>& schools, vector<string>& data);
    string inputFile();
    void buildFastLookup(vector<School*>& data, unordered_map<string, School*>& fast_lookup);
    void printSchools(vector<School*>& schools);
    void findSchoolByName(string name, vector<School*>& schools, vector<School*>& found);
    static bool sortByName(School* a, School* b);
    bool isYes(string value);
    string outputPath(string filename);
public:
    Challenge(IIOStorage* ioStorage);
    ~Challenge();
    void Execute();
};

Challenge::Challenge(IIOStorage* ioStorage)
    : _ioStorage(ioStorage) {}

Challenge::~Challenge()
{
    delete _ioStorage;

    for(School* school : _schools)
    {
        delete school;
    }
}

void Challenge::Execute()
{
    vector<string> data;
    
    _ioStorage->readFile(inputFile(), data);

    buildSchoolList(_schools, data);

    buildFastLookup(_schools, _schoolsFastLookup);

    while(true)
    {
        switch(printMenu())
        {
            case 1:
                searchByName();
            break;
            case 2:
                searchByDBN();
            break;
            case 3:
                return;
            break;
        }
    }
}

int Challenge::printMenu()
{
    int option;

    cout << "[1] Search by Name" << endl;
    cout << "[2] Search by DBN" << endl;
    cout << "[3] Exit" << endl;
    cout << "Option: ";
    cin >> option;

    return option;
}

void Challenge::searchByName()
{
    string name, filename, want_to_save;
    vector<School*> filtered_schools;

    cout << "Name: ";
    cin >> name;

    findSchoolByName(name, _schools, filtered_schools);

    sort(filtered_schools.begin(), filtered_schools.end(), sortByName);

    cout << "Schools found:" << endl;

    printSchools(filtered_schools);

    cout << "Do you want to save in csv? (y/Y/Yes): ";
    cin >> want_to_save;

    if (isYes(want_to_save))
    {
        cout << "Filename: ";
        cin >> filename;

        string fullpath_filename = outputPath(filename);

        _ioStorage->createDirectory(OUTPUT_DIRECTORY);

        if (_ioStorage->writeCSV(fullpath_filename, filtered_schools))
        {
            cout << "Data has been written to: " << fullpath_filename << endl;
        }
    }
}

void Challenge::searchByDBN()
{
    string dbn;

    cout << "DBN: ";
    cin >> dbn;

    auto it = _schoolsFastLookup.find(dbn);

    if (it != _schoolsFastLookup.end())
    {
        cout << (*it).second->toString() << endl << endl;
    }
}

void Challenge::buildSchoolList(vector<School*>& schools, vector<string>& data)
{
    int total = data.size();

    for (int i = SKIP_CSV_HEADER; i < total; ++i)
    {
        schools.push_back(School::create(data[i]));
    }
}

string Challenge::inputFile()
{
    stringstream ss;

    ss << ".";
    ss << SEP;
    ss << INPUT_DIRECTORY;
    ss << SEP;
    ss << INPUT_FILE;

    return ss.str();
}

void Challenge::buildFastLookup(vector<School*>& schools, unordered_map<string, School*>& fast_lookup)
{
    for (auto& school : schools)
    {
        fast_lookup[school->dbn()] = school;
    }
}

void Challenge::printSchools(vector<School*>& schools)
{
    int i = 1;

    for(auto* school : schools)
    {
        cout << i << ": " << school->toString() << endl;
        i++;
    }
}

void Challenge::findSchoolByName(string name, vector<School*>& schools, vector<School*>& found)
{
    uppercase(name);

    for(auto* school : schools)
    {
        string school_name = school->name();
        
        uppercase(school_name);
        
        if (school_name.find(name) != -1)
        {
            found.push_back(school);
        }
    }
}

bool Challenge::sortByName(School* a, School* b)
{
    return a->name() < b->name();
}

bool Challenge::isYes(string value)
{
    uppercase(value);

    return value == "Y" || value == "YES";
}

string Challenge::outputPath(string filename)
{
    std::stringstream ss;

    ss << ".";
    ss << SEP;
    ss << OUTPUT_DIRECTORY;
    ss << SEP;
    ss << filename;

    return ss.str();
}

#endif