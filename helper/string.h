#ifndef __STRING_H__
#define __STRING_H__

#include <string>
#include <algorithm>

using namespace std;

void uppercase(string& str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);;
}

void lowercase(string& str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);;
}

#endif