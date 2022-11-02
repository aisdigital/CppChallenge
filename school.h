#ifndef __SCHOOL_H__
#define __SCHOOL_H__

#include <string>

using namespace std;

class school
{
private:
    const int NOT_PRESENT = -1;
    string _dbn;
    string _name;
    int _number_test_takers = NOT_PRESENT;
    int _critical_reading_mean = NOT_PRESENT;
    int _mathematics_mean = NOT_PRESENT;
    int _writing_mean = NOT_PRESENT;
    school(string dbn, string name, int number_test_takers, int critical_reading_mean, int mathematics_mean, int writing_mean);

public:    
    ~school();
    school* create(string data);
};


#endif