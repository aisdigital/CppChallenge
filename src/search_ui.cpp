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

void printMainMenuSearchByName(string &keyword)
{
    string openMsg("*************************** Search by name ***************************\n\n"\
                   "Please, enter the keyword to search:");

    string userOpt("Keyword: ");

    cout << openMsg << endl << endl;

    cout << userOpt;

    // Clearing the cin buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // to-do: filter the user input
    getline(cin, keyword); // Use getline() to read spaces as well

    cout << endl;
}

uiFlag printExpMenuSearchByName(string &fileName)
{
    string saveOpt;

    string openMsg("*************************** Search by name ***************************");

    string userOpt1("Would you like to export the results? [Y/n] ");

    string userOpt2("Please, enter the name of the file to export: ");

    cout << openMsg << endl << endl;

    cout << userOpt1;

    // to-do: filter the user input
    cin >> saveOpt;  

    if((saveOpt != "y") && (saveOpt != "Y")) {
        return NO_EXP;
    } 

    cout << endl << userOpt2;

    // to-do: filter forbidden characters
    cin >> fileName;

    return DO_EXP;
}

void printMenuSearchByDBN(string &dbn)
{
    string openMsg("*************************** Search by DBN ****************************\n\n"\
                   "Please, enter the school DBN:");

    string userOpt("DBN: ");

    cout << openMsg << endl << endl;

    cout << userOpt;

    // to-do: filter the user input
    cin >> dbn;
}
