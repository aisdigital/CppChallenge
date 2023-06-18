#include "Printer.h"

#include <iostream>
#include <limits>

void Printer::printLoading() {
	std::cout << "\n";
	std::cout << "Welcome! Please wait while we load the data.";
	std::cout << "\n" << std::endl;
}

int Printer::printMain() {
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

std::string Printer::printSearchByDbn() {
	std::string dbn;

	std::cout << "\nType DBN and press Enter: ";
	std::cout.flush();
	std::cin >> dbn;

	return trim(dbn);
}

std::string Printer::printSearchByName() {
	std::string name;

	std::cout << "\nType the school name and press Enter: ";
	std::cout.flush();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, name);

	return trim(name);
}

void Printer::printRecord(const Record& record) {
    std::cout << "\n*** Record ***\n";
    std::cout << "DBN: " << record.dbn << "\n";
    std::cout << "School Name: " << record.schoolName << "\n";
    std::cout << "Test Takers: " << record.testTakers << "\n";
    std::cout << "Critical Reading Mean: " << record.criticalReadingMean << "\n";
    std::cout << "Mathematics Mean: " << record.mathsMean << "\n";
    std::cout << "Writing Mean: " << record.writingMean << "\n";
    std::cout << std::endl;
}

char Printer::printOutputQuestion() {
	std::string input;

	std::cout << "\nWould you like to save the search result in an output?";
	std::cout << "\nPress y or n and Enter to select your choice: ";
	std::cout.flush();
	std::getline(std::cin, input);

	return std::tolower(input[0]);
}

std::string Printer::trim(const std::string& s) {
	auto pos = s.find_last_not_of(' ');
	return s.substr(0, pos + 1);
}

