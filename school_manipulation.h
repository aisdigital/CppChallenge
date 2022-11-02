#ifndef __SCHOOL_MANIPULATION_H__
#define __SCHOOL_MANIPULATION_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include "school.h"

using namespace std;

vector<school*> build_school_list(vector<string> data)
{
    vector<school*> school_list;

    for (auto& d : data)
    {
        school* school = school::create(d);
        school_list.push_back(school);
    }

    return school_list;
}

void print_schools(vector<school*>& schools)
{
    int i = 1;

    for(auto* school : schools)
    {
        cout << i << ": " << school->to_string() << endl;
        i++;
    }
}

void build_school_fast_lookup(vector<school*> data, unordered_map<string, school*>& fast_lookup)
{
    for (auto& d : data)
    {
        fast_lookup[d->dbn()] = d;
    }
}

#endif