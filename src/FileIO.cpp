#include "FileIO.h"

FileIO::~FileIO()
{
    closeFile();
}

void FileIO::closeFile()
{
    if(m_fstream.is_open())
        m_fstream.close();
}