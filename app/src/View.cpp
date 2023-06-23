#include "View.hpp"

View::View() {}

View::~View() {}

void View::printMenu() {
    std::cout << "\n\n\n\n\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "|       SAT RESULTS         |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "| 1. Search by DBN          |" << std::endl;
    std::cout << "| 2. Search by School Name  |" << std::endl;
    std::cout << "| 3. Exit                   |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int View::getUserOption() {
    std::cout << "Select your option: ";
    int option;
    std::cin >> option;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid option (1-4): ";
        std::cin >> option;
    }
    return option;
}