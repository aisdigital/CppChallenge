#ifndef READTHREAD_H
#define READTHREAD_H

#include <thread>
#include "readfileinterface.h"

using std::thread;

/**
 * @brief Thread responsible to read a file
 */
class ReadThread : public thread {

public:
    /**
     * @brief Constructor
     * 
     * @param newReadFile
     */
    ReadThread(ReadFileInterface* newReadFile);

    /**
     * @brief Destructor
     */
    ~ReadThread();

    /**
     * @brief Run thread
     */
    void run();
    
private:
    ReadFileInterface* m_readFile; /**< File reader object*/
};

#endif // READTHREAD_H