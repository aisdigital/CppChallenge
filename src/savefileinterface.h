#ifndef SAVEFILEINTERFACE_H
#define SAVEFILEINTERFACE_H

#include <string>
#include <vector>

using std::vector;
using std::string;

/**
 * @brief The SaveFileInterface abstract class represents any file saver
 */
class SaveFileInterface {

public:
    /**
     * @brief Virtual destructor
     */
    virtual ~SaveFileInterface(){}
    /**
     * @brief Virtual save method
     * 
     * @param data
     * @param name
     */
    virtual bool save(vector<string> data, string name) = 0;
};

#endif // SAVEFILEINTERFACE_H