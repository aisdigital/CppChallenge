#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>

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

void search_by_dbn()
{
    cout << "search_by_dbn" << endl;
}

#endif