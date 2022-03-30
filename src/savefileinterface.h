#ifndef SAVEFILEINTERFACE_H
#define SAVEFILEINTERFACE_H

#include <string>
#include <vector>

using std::vector;
using std::string;

class SaveFileInterface {

public:
    virtual ~SaveFileInterface(){}

    virtual bool save(vector<string> data, string name) = 0;
};

#endif // SAVEFILEINTERFACE_H