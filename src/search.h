#ifndef SEARCH_H
#define SEARCH_H

#include "searchinterface.h"
#include "fileinterface.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Search : public SearchInterface {

public:
    Search();

    ~Search();

    vector<string> searchName(string filter);

    vector<string> searchDbn(string filter);

    void showResult(vector<string> finalResult);

private:
    vector<string> sortData(vector<string> data);
};

#endif // SEARCH_H