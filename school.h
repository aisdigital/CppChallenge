#ifndef __SCHOOL_H__
#define __SCHOOL_H__

#include <string>
#include <sstream>
#include <vector>
#include "vector_helper.h"

using namespace std;

class school
{
private:
    static const int NOT_PRESENT = -1;
    string _dbn;
    string _name;
    int _number_test_takers = NOT_PRESENT;
    int _critical_reading_mean = NOT_PRESENT;
    int _mathematics_mean = NOT_PRESENT;
    int _writing_mean = NOT_PRESENT;
    static string get_mean(int mean);
    static int extract_score(string data);
    static vector<string> extract_fields(string data);
    school(string dbn, string name, int number_test_takers, int critical_reading_mean, int mathematics_mean, int writing_mean);

public:    
    ~school();
    string to_string();
    string to_csv();
    static school* create(string data);
};

school::school(std::string dbn, std::string name, int number_test_takers, int critical_reading_mean, int mathematics_mean, int writing_mean)
    : _dbn(dbn),
    _name(name),
    _number_test_takers(number_test_takers),
    _critical_reading_mean(critical_reading_mean),
    _writing_mean(writing_mean)
{}

school::~school()
{
}

school* school::create(string data)
{
    vector<string> fields = school::extract_fields(data);

    return new school(
        get_vector_value<string>(fields, 0, ""),
        get_vector_value<string>(fields, 1, ""),
        school::extract_score(get_vector_value<string>(fields, 2, "")),
        school::extract_score(get_vector_value<string>(fields, 3, "")),
        school::extract_score(get_vector_value<string>(fields, 4, "")),
        school::extract_score(get_vector_value<string>(fields, 5, ""))
    );
}

string school::get_mean(int mean)
{
    return mean == NOT_PRESENT
        ? ""
        : std::to_string(mean);
}

vector<string> school::extract_fields(string data)
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

int school::extract_score(string data)
{
    return data.empty()
        ? school::NOT_PRESENT
        : stoi(data);
}

string school::to_csv()
{
    stringstream ss;

    ss << _dbn
        << ","
        << _name
        << ","
        << school::get_mean(_number_test_takers)
        << ","
        << school::get_mean(_critical_reading_mean)
        << ","
        << school::get_mean(_mathematics_mean)
        << ","
        << school::get_mean(_writing_mean);

    return ss.str();
}

string school::to_string()
{
    stringstream ss;

    ss << "DBN: "
        << _dbn
        << ", Name: "
        << _name
        << ", Number Test Takers: "
        << school::get_mean(_number_test_takers)
        << ", Critical Reading Mean: "
        << school::get_mean(_critical_reading_mean)
        << ", Mathematics Mean: "
        << school::get_mean(_mathematics_mean)
        << ", Writing Mean: "
        << school::get_mean(_writing_mean);

    return ss.str();
}
#endif