#include <list>

#include "FileReader.h"

using std::list;
using std::ios_base;

bool FileReader::openFile(string fileName)
{
    m_fstream.open(fileName, ios_base::in);

    return m_fstream.is_open();
}

list<string> FileReader::getLines()
{
    list<string> result;
    string line;

    if(m_fstream.is_open())
    {
        while(std::getline(m_fstream, line))
            result.push_back(line);
    }

    return result;
}
