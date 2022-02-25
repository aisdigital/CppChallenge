#include "SATResultsManager.h"
#include "utils.h"

#include <iostream>

vector<string> SATResultsManager::splitLine(string line)
{
    int start=0, pos;
    string token;
    vector<string> result;

    pos=line.find(',');
    while(pos != string::npos)
    {
        token = line.substr(start, pos-start);
        result.push_back(token);

        start = pos+1;
        pos = line.find(',', start);
    }

    if(start < line.length())
        result.push_back(line.substr(start, line.length()-start));
    else
        result.push_back("");    

    return result;
}

bool SATResultsManager::isHeader(string line)
{
    string token = extractDBN(line);;

    if(token == "DBN")
        return true;

    return false;
}

bool SATResultsManager::checkFields(string line)
{
    vector<string> fields = splitLine(line);
    if(fields.size() == 6)
        return true;

    return false;
}

string SATResultsManager::extractDBN(string line)
{
    vector<string> fields = splitLine(line);

    return fields[0];
}

string SATResultsManager::extractName(string line)
{
    vector<string> fields = splitLine(line);

    return fields[1];
}

bool SATResultsManager::addData(list<string> data)
{
    list<string>::iterator it;
    string code;
    bool result = true;

    it=data.begin();
    if(isHeader(*it))
        it++;

    for(; it!=data.end() ; it++)
    {
        if(checkFields(*it))
        {
            code = extractDBN(*it);
            m_SATResults[code] = *it;
        }
        else
            result = false;
    }
    return result;
}

list<string> SATResultsManager::findByName(string name)
{
    list<string> result;
    map<string, string>::iterator it;
    string schoolName;
    
    for(it=m_SATResults.begin() ; it!=m_SATResults.end() ; it++)
    {
        schoolName = extractName(it->second);
        if(stringToLower(schoolName).find(stringToLower(name)) != string::npos)
            result.push_back(it->second);
    }

    if(result.size() == 0)
        result.push_back("No results found");

    return result;
}

string SATResultsManager::findByDBN(string code)
{
    map<string, string>::iterator it;

    it = m_SATResults.find(code);
    if(it != m_SATResults.end())
        return it->second;

    return "No result found";
}