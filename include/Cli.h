#pragma once

#include <string>

class Cli {
    void printBlankLine();
    void printLine(const std::string &text);
    
public:
    enum class MenuOption {
        Invalid,
        SearchByName,
        SearchByDbn,
        Exit
    };

    void showMenu();
    MenuOption getUserMenuOption();
    bool getUserConfirmation(std::string question);
    std::string getUserInput(std::string predicate);
    void close();
};