#include "View.hpp"

View::View() {}

View::~View() {}

/// @brief Print formatted menu
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

/// @brief Prompts user to enter the desired option
/// @return Selected option
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

/// @brief Ask user for DBN to search
/// @return DBN value
std::string View::queryDbn() {
    std::cout << "Enter DBN: ";

    std::string dbn;
    std::cin >> dbn;
    return dbn;
}

/// @brief Ask user for school name to search
/// @return School name value
std::string View::querySchoolName() {
    std::cout << "Enter school name: ";

    std::string schoolName;
    std::cin >> schoolName;
    return schoolName;
}

/// @brief Ask user for output file name
/// @return Output file name
std::string View::querySaveFileName() {
    std::cout << "Enter output file name: ";

    std::string outputName;
    std::cin >> outputName;
    return outputName;
}

/// @brief Ask user to confirm if search results should be saved to file
/// @return Bool confirmation value
bool View::querySaveFile() {
    while(true) {
        char input;
        std::cout << "Save search results? [y/n]";
        std::cin >> input;
        if(input == 'y' || input == 'Y') {
            return true;
        }
        else if (input == 'n' || input == 'N') {
            return false;
        }
        else {
            std::cout << "Invalid input. Please try again.\n";
            // Clear the input buffer
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
    }
}

void View::showWarningNotFound(std::string searchTerm) {
    std::cout << "\nNo results were found for " << "\033[33m" << searchTerm << "\033[0m" << std::endl;
}

void View::printRecord(DatabaseRecord record) {
    std::cout << "\n---------------------------------------------------------------------" << std::endl;
    std::cout << "DBN: " << record.getDbn() << std::endl;
    std::cout << "School Name: " << record.getSchoolName() << std::endl;
    std::cout << "Test Takers: " << record.getTestTakers() << std::endl;
    std::cout << "Critical Reading Mean: " << record.getCriticalReadingMean() << std::endl;
    std::cout << "Mathematics Mean: " << record.getMathMean() << std::endl;
    std::cout << "Writing Mean: " << record.getWritingMean() << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
}

void View::waitInputReturnToMenu() {
    while (std::cin.get() != 'c') {
        std::cout << "\nEnter [c] to continue to menu: ";
    }
}

void View::showExitMsg() {
    std::cout << "\nExiting..." << std::endl;
}