#ifndef __FILE_HELPER_H__
#define __FILE_HELPER_H__

#include <vector>
#include <fstream>

using namespace std;

vector<string> read_file(string filename)
{
    vector<string> data;
    ifstream fileCsv(filename);
    string buffer;

    while (getline(fileCsv, buffer))
    {
        data.push_back(buffer);
    }

    fileCsv.close();

    return data;
}

#endif 