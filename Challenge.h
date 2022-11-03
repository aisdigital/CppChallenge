#ifndef __CHALLENGE_H__
#define __CHALLENGE_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Configuration.h"
#include "Constant.h"
#include "IOStorage.h"
#include "School.h"

#define SKIP_FIRST_ITEM 1

using namespace std;

class Challenge
{
private:
    IIOStorage* _ioStorage = nullptr;
    vector<School*> _schools;
    unordered_map<string, School*> schoolsFastLookup;
    int printMenu();
    void searchByName();
    void searchByDBN();
    vector<School*> buildSchoolList(vector<string> data);
    string inputFile();
    void buildFastLookup(vector<School*> data, unordered_map<string, School*>& fast_lookup);
    void printSchools(vector<School*> schools);
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
    vector<string> data = _ioStorage->readFile(inputFile());
    _schools = buildSchoolList(vector<string>(data.begin() + SKIP_FIRST_ITEM, data.end()));
    
    buildFastLookup(_schools, schoolsFastLookup);

    _ioStorage->writeCSV("dir", _schools);

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
    cout << "searchByName" <<endl;
}

void Challenge::searchByDBN()
{
    string dbn;

    cout << "DBN: ";
    cin >> dbn;

    auto it = schoolsFastLookup.find(dbn);

    if (it != schoolsFastLookup.end())
    {
        cout << (*it).second->toString() << endl << endl;
    }
}

vector<School*> Challenge::buildSchoolList(vector<string> data)
{
    vector<School*> schools;

    for (auto& d : data)
    {
        School* school = School::create(d);
        schools.push_back(school);
    }

    return schools;
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

void Challenge::buildFastLookup(vector<School*> schools, unordered_map<string, School*>& fast_lookup)
{
    for (auto& school : schools)
    {
        fast_lookup[school->dbn()] = school;
    }
}

void Challenge::printSchools(vector<School*> schools)
{
    int i = 1;

    for(auto* school : schools)
    {
        cout << i << ": " << school->toString() << endl;
        i++;
    }
}

#endif