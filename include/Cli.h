#pragma once

#include <string>

class Cli {
    void printLine(const std::string &text);
    void printBlankLine();
    
public:
    enum class MenuOption {
        Invalid,
        SearchByName,
        SearchByDbn,
        Exit
    };

    void showMenu();
    MenuOption getUserOption();
};