#ifndef READTHREAD_H
#define READTHREAD_H

#include <thread>
#include "readfileinterface.h"

using std::thread;

class ReadThread : public thread {

public:
    ReadThread(ReadFileInterface* newReadFile);
    ~ReadThread();
    void run();
    
private:
    ReadFileInterface* m_readFile;
};

#endif // READTHREAD_H