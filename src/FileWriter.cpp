#include "FileWriter.h"

using std::ios_base;
using std::endl;

bool FileWriter::openFile(string fileName)
{
    m_fstream.open(fileName, ios_base::out);

    return m_fstream.is_open();   
}

void FileWriter::writeLine(string line)
{
    if(m_fstream.is_open())
        m_fstream << line << endl;
}
