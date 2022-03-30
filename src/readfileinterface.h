#ifndef READFILEINTERFACE_H
#define READFILEINTERFACE_H

class ReadFileInterface {

public:
    virtual ~ReadFileInterface(){}

    virtual void read() = 0;
};

#endif // READFILEINTERFACE_H