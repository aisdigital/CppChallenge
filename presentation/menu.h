#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <unordered_map>

using namespace std;

int print_menu()
{
    int option;

    cout << "[1] Search by Name" << endl;
    cout << "[2] Search by DBN" << endl;
    cout << "[3] Exit" << endl;
    cout << "Option: ";
    cin >> option;

    return option;
}

void search_by_name()
{
    cout << "search_by_name" << endl;
}

void search_by_dbn(unordered_map<string, school*> schools_fast_lookup)
{
    string dbn;

    cout << "DBN: ";
    cin >> dbn;
    cout << endl;

    auto it = schools_fast_lookup.find(dbn);

    if (it != schools_fast_lookup.end())
    {
        cout << "FOUND: " << endl << (*it).second->to_string() << endl;
    }

    cout << endl;
}

#endif