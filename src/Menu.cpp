#include "Menu.h"

#include <iostream>

void Menu::printLoading() {
	std::cout << "\n";
	std::cout << "Welcome! Please wait while we load the data.";
	std::cout << "\n" << std::endl;
}

int Menu::printMain() {
	std::string option;

	std::cout << "\nSelect option:\n";
	std::cout << "(1) Search by name\n";
	std::cout << "(2) Search by DBN\n";
	std::cout << "(3) Exit\n";
	std::cout << "Type option and press Enter: ";
	std::cout.flush();
	std::cin >> option;

	return std::stoi(option);
}

std::string Menu::printSearchByDbn() {
	std::string dbn;

	std::cout << "\nType DBN and press Enter: ";
	std::cout.flush();
	std::cin >> dbn;

	return dbn;
}

std::string Menu::printSearchByName() {
	std::string name;

	std::cout << "\nType the school name and press Enter: ";
	std::cout.flush();
	std::getline(std::cin, name);

	return name;
}

