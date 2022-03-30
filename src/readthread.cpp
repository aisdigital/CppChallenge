#include "readthread.h"
#include <iostream>

ReadThread::ReadThread(ReadFileInterface* newReadFile)
{
    m_readFile = newReadFile;
}

ReadThread::~ReadThread()
{

}

void ReadThread::run()
{
    m_readFile->read();
}
