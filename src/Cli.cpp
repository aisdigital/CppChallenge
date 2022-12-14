#include <iostream>

#include "Cli.h"

void Cli::printLine(const std::string &text) {
    std::cout << text << std::endl;
}

void Cli::printBlankLine() {
    std::cout << std::endl;
}

void Cli::showMenu() {
    printBlankLine();
    printLine("=====================================================");
    printLine("===========   SAT College Board Results   ===========");
    printLine("=====================================================");
    printBlankLine();
    printLine("Options:");
    printBlankLine();
    printLine("1 -> Search School SAT result by name");
    printLine("2 -> Search School SAT result by DBN");
    printLine("3 -> Exit");
    printBlankLine(); 
}

Cli::MenuOption Cli::getUserMenuOption() {
    std::string option;
    std::cout << "Type your option and press 'Enter': ";
    std::cin >> option;
    
    if (option == "1") {
        return MenuOption::SearchByName;
    }
    else if (option == "2") {
        return MenuOption::SearchByDbn;
    }
    else if (option == "3") {
        return MenuOption::Exit;
    }
    else {
        return MenuOption::Invalid;
    }
}

bool Cli::getUserConfirmation(std::string question) {
    std::string answer;
    std::cout << question << " [y/n]: ";
    std::cin.ignore();
    std::getline(std::cin, answer);
    return (answer == "y");
}

std::string Cli::getUserInput(std::string predicate) {
    std::string inputText;
    std::cout << predicate << ": ";
    std::cin.ignore();
    std::getline(std::cin, inputText);
    return inputText;
}

void Cli::close() {
    printBlankLine();
    printLine("Closing application...");
    printBlankLine();
}