#ifndef SEARCHINTERFACE_H
#define SEARCHINTERFACE_H

#include "fileinterface.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

using std::vector;

class SearchInterface {

public:
    virtual ~SearchInterface(){}

    virtual vector<string> searchName(string filter) = 0;

    virtual vector<string> searchDbn(string filter) = 0;

private:
    virtual vector<string> sortData(vector<string> data) = 0;
};

#endif // SEARCHINTERFACE_H