#ifndef __SCHOOL_H__
#define __SCHOOL_H__

#include <string>
#include <sstream>
#include <vector>
#include "helper/vector.h"

using namespace std;

class School
{
private:
    string _dbn;
    string _name;
    int _numberTestTakers = NOT_PRESENT;
    int _criticalReadingMean = NOT_PRESENT;
    int _mathematicsMean = NOT_PRESENT;
    int _writingMean = NOT_PRESENT;
    static string getMean(int mean);
    static int extractScore(string data);
    static vector<string> extractFields(string data);
    School(string dbn, string name, int numberTestTakers, int criticalReadingMean, int mathematicsMean, int writingMean);

public:    
    ~School();
    string toString();
    string toCSV();
    static School* create(string data);
    string name();
    string dbn();
    int numberReadingMean();
    int criticalReadingMean();
    int mathematicsMean();
    int writingMean();
    static const int NOT_PRESENT = -1;
};

School::School(std::string dbn, std::string name, int numberTestTakers, int criticalReadingMean, int mathematicsMean, int writingMean)
    : _dbn(dbn),
    _name(name),
    _numberTestTakers(numberTestTakers),
    _criticalReadingMean(criticalReadingMean),
    _writingMean(writingMean)
{}

School::~School()
{
}

School* School::create(string data)
{
    vector<string> fields = School::extractFields(data);

    return new School(
        get_vector_value<string>(fields, 0, ""),
        get_vector_value<string>(fields, 1, ""),
        School::extractScore(get_vector_value<string>(fields, 2, "")),
        School::extractScore(get_vector_value<string>(fields, 3, "")),
        School::extractScore(get_vector_value<string>(fields, 4, "")),
        School::extractScore(get_vector_value<string>(fields, 5, ""))
    );
}

string School::getMean(int mean)
{
    return mean == NOT_PRESENT
        ? ""
        : std::to_string(mean);
}

vector<string> School::extractFields(string data)
{
    vector<string> fields;
    string buffer = "";
    bool is_string = false;

    for (auto& c : data)
    {
        if (c == ',' && is_string == false)
        {
            fields.push_back(buffer);
            buffer = "";
        }
        else if (c == '"')
        {
            is_string = !is_string;
        }
        else
        {
            buffer += c;
        }
    }

    fields.push_back(buffer);

    return fields;
}

int School::extractScore(string data)
{
    return data.empty()
        ? School::NOT_PRESENT
        : stoi(data);
}

string School::toCSV()
{
    stringstream ss;

    ss << _dbn
        << ","
        << _name
        << ","
        << School::getMean(_numberTestTakers)
        << ","
        << School::getMean(_criticalReadingMean)
        << ","
        << School::getMean(_mathematicsMean)
        << ","
        << School::getMean(_writingMean);

    return ss.str();
}

string School::toString()
{
    stringstream ss;

    ss << "DBN: "
        << _dbn
        << ", Name: "
        << _name
        << ", Number Test Takers: "
        << School::getMean(_numberTestTakers)
        << ", Critical Reading Mean: "
        << School::getMean(_criticalReadingMean)
        << ", Mathematics Mean: "
        << School::getMean(_mathematicsMean)
        << ", Writing Mean: "
        << School::getMean(_writingMean);

    return ss.str();
}

string School::name()
{
    return this->_name;
}

string School::dbn()
{
    return this->_dbn;
}

int School::numberReadingMean()
{
    return this->_numberTestTakers;
}

int School::criticalReadingMean()
{
    return this->_criticalReadingMean;
}

int School::mathematicsMean()
{
    return this->_mathematicsMean;
}

int School::writingMean()
{
    return this->_writingMean;
}
#endif