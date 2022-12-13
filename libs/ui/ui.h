#ifndef UI_H
#define UI_H

#include <map>
#include <string>
#include <iostream>

class UI 
{
    private:
    int menuSelectedOption {-1};
    std::map<int, std::string> mapOfOptions;

    public:
    void printMenu(const std::string& menuHeader, const std::map<int, std::string>& mapOfFiles);
    void printLine();
};






#endif