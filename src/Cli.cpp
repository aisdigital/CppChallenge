#include <iostream>

#include "Cli.h"

void Cli::printLine(const std::string &text) {
    std::cout << text << std::endl;
}

void Cli::printBlankLine() {
    std::cout << std::endl;
}

void Cli::showMenu() {
    printLine("Options:");
    printBlankLine();
    printLine("[ 1 ] Search School SAT result by name");
    printLine("[ 2 ] Search School SAT result by DBN");
    printLine("[ 3 ] Exit");
    printBlankLine(); 
}

Cli::MenuOption Cli::getUserOption() {
    int option = 0;
    printLine("Enter the option number and press 'Enter'");
    std::cin >> option;
    
    switch (option) {
    case 1:
        return MenuOption::SearchByName;
    case 2:
        return MenuOption::SearchByDbn;
    case 3:
        return MenuOption::Exit;
    default:
        return MenuOption::Invalid;
    }
}

std::string Cli::getUserSearchText() {
    std::string inputText;
    std::cout << "Search: ";
    std::cin >> inputText;
    return inputText;
}

void Cli::open() {
    printBlankLine();
    printLine("=====================================================");
    printLine("===========   SAT College Board Results   ===========");
    printLine("=====================================================");
    printBlankLine();
}

void Cli::close() {
    printBlankLine();
    printLine("Closing application...");
    printBlankLine();
}