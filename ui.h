#ifndef UI_H
#define UI_H

#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
class UI
{
    public:
        UI() = default;
        ~UI() = default;
        void printFilesMenu(const std::map<int, std::string> &filesMap);
        void printStartFileRead(const std::string &filePath);
        void printSATFilterMenu();
        void getOptionInput(int &optionValue);
        

};

#endif