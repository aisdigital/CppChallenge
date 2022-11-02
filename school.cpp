#include "school.h"

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

}

string school::to_csv()
{
    stringstream ss;

    ss << _dbn
        << ","
        << _name
        << ","
        << get_mean(_number_test_takers)
        << ","
        << get_mean(_critical_reading_mean)
        << ","
        << get_mean(_mathematics_mean)
        << ","
        << get_mean(_writing_mean);

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
        << get_mean(_number_test_takers)
        << ", Critical Reading Mean: "
        << get_mean(_critical_reading_mean)
        << ", Mathematics Mean: "
        << get_mean(_mathematics_mean)
        << ", Writing Mean: "
        << get_mean(_writing_mean);

    return ss.str();
}

string school::get_mean(int mean)
{
    return mean == NOT_PRESENT
        ? ""
        : std::to_string(mean);
}