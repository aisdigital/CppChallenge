#include "search.h"
#include "csvfile.h"

#include <iostream>
#include<bits/stdc++.h>

#define INITIAL_NAME_POSITION 7

using std::iostream;

Search::Search()
{

}

Search::~Search()
{
    
}

vector<string> Search::searchName(string filter)
{
    vector<string> file = CsvFile::getInstance()->getCsvFile();
    vector<string> unsortedResult; 
    vector<string> result;

    for(int i = 0; i < file.size(); i++)
    {
        if(file[i].find(filter) != string::npos)
        {
            unsortedResult.push_back(file[i]);
        }
    }
    result = sortData(unsortedResult);
    return result;
}

vector<string> Search::searchDbn(string filter)
{
    vector<string> file = CsvFile::getInstance()->getCsvFile();
    vector<string> result;

    for(int i = 0; i < file.size(); i++)
    {
        if(file[i].find(filter) != string::npos)
        {
            result.push_back(file[i]);
        }
    }
    
    return result;
}

vector<string> Search::sortData(vector<string> data)
{
    vector<string> result;
    vector<string> nameResult;

    for(int i = 0; i < data.size(); i++)
    {
        int initialPosition = data[i].find(",");
        int lastPosition = data[i].find(",", initialPosition + 1);
        char name[lastPosition - (initialPosition + 1)];
        std::size_t lenght = data[i].copy(name, lastPosition - (initialPosition + 1), (initialPosition + 1));
        name[lenght] = '\0';
        nameResult.push_back(name);
    }

    sort(nameResult.begin(), nameResult.end());

    for(int j = 0; j < data.size(); j++)
    {
        for(int k = 0; k < nameResult.size(); k++)
        {
            if(data[k].find(nameResult[j]) != string::npos)
            {
                result.push_back(data[k]);
                break;
            }
        }
    }
    
    return result;
}

void Search::showResult(vector<string> finalResult)
{
    for(int i = 0; i < finalResult.size(); i++)
    {
        std::cout << finalResult[i] << std::endl;
    }
}