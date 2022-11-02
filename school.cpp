#include "school.h"

school::school(std::string dbn, std::string name, int number_test_takers, int critical_reading_mean, int mathematics_mean, int writing_mean)
{
    this->_dbn = dbn;
    this->_name = name;
    this->_number_test_takers = number_test_takers;
    this->_critical_reading_mean = critical_reading_mean;
    this->_mathematics_mean = mathematics_mean;
    this->_writing_mean = writing_mean;
}

school::~school()
{
}

school* school::create(string data)
{

}