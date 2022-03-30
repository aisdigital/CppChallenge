#ifndef FILEINTERFACE_H
#define FILEINTERFACE_H

class FileInterface {

public:
    virtual ~FileInterface(){}

    virtual FileInterface* getInstance() = 0;
};

#endif // FILEINTERFACE_H