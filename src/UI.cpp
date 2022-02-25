#include <iostream>

#include "UI.h"
#include "utils.h"

using std::cout;
using std::cin;
using std::endl;

void UI::showError(string error)
{
    cout << "\e[31mError:\e[0m ";
    showMessage(error);
}

void UI::showMessage(string message)
{
    cout << message << endl;
}

int UI::getUserOption(list<string> options)
{
    list<string>::iterator it;
    int index;
    string showOptions = "";
    string userOption;

    for(it=options.begin() ; it!=options.end() ; it++)
        showOptions = showOptions+*it+"/";
    
    if(showOptions.empty())
    {
        showError("Invalid options!");
        exit(1);
    }
    else
        showOptions.resize(showOptions.length()-1);

    while(true)
    {
        cout << '[' << showOptions << "]: ";
        cin >> userOption;

        // Validate user input
        for(it=options.begin(),index=0 ; it!=options.end() ; it++,index++)
        {
            if((stringToLower(userOption).compare(stringToLower(*it))) == 0)
                return index;
        }
    }
}

string UI::getUserString()
{
    string result = "";

    while(result.empty())
        cin >> result;
    cin.get(); // Get residual '\n'

    return result;
}

void UI::reset()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

void UI::waitUser()
{
    showMessage("Tap 'Enter' to continue...");
    while(cin.get() != '\n');
}
