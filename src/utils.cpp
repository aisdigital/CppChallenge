#include "utils.h"

string stringToLower(string str)
{
    int i;
    string lower;

    for(i=0 ; i<(int)str.length() ; i++)
    {
        if((str[i] >= 'A') && (str[i] <= 'Z'))
            lower += str[i]-'A'+'a';
        else
            lower += str[i]; 
    }

    return lower;
}