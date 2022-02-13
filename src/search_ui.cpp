/** \file search_ui.cpp
 *  \brief Implementation of useful user interface functions.
 */

#include "search_ui.h"

// *************** Methods implementation *******************************

void printMainMenu(int &option)
{
    string openMsg("****************************** Welcome! ******************************\n\n"\
                   "Please, choose one of the three options below:");

    string opt1("1 - Search by the school name");
    string opt2("2 - Search by the school DBN");
    string opt3("3 - Exit");
    string userOpt("Option [3]: ");
    
    cout << openMsg << endl << endl;
    cout << opt1 << endl;
    cout << opt2 << endl;
    cout << opt3 << endl << endl;
    cout << userOpt;

    // to-do: filter user input
    cin >> option;
}
/*
void printMainMenuSearchByName(string &keyword)
{

}

uiFlag printExpMenuSearchByName(string &fileName)
{

}

void printMenuSearchByDBN(string &dbn)
{

}
*/