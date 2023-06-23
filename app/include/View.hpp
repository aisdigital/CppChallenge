#include <iostream>

/*
View.hpp: this class is responsible to print the menu and interact with the user
Author: Lucca Leão
Date: 23/06/2023
*/

class View {
public:
    View();
    ~View();
    
    void printMenu();
    int getUserOption();
};