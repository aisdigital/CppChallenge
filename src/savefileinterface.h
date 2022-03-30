#ifndef SAVEFILEINTERFACE_H
#define SAVEFILEINTERFACE_H

class SaveFileInterface {

public:
    virtual ~SaveFileInterface(){}

    virtual bool save() = 0;
};

#endif // SAVEFILEINTERFACE_H