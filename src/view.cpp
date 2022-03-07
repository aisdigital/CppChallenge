/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/view.cpp
 **/

#include <iostream>

#include "view.h"

namespace CppChallenge {
namespace View {
    
view::view() {
}

view::~view() {}

void view::PrintLine(const std::string &print_string) {
    Print(print_string);
    std::cout << std::endl;
}

void view::PrintLine() const {
    std::cout << std::endl;
}

void view::Print(const std::string &print_string) const {
    std::cout << print_string;
}

uint view::ReadInt() const {
    uint input_read;
    std::cin >> input_read;
    if (std::cin) {
        return input_read;
    } else {
        std::cin.clear();
        std::cin.ignore();
        return 0;
    }
}

std::string view::ReadString() const {
    std::string input_read;
    std::cin >> input_read;
    return input_read;
}

uint view::ReadYesNoConfirmation() const {
    char input_read;
    std::cin >> input_read;
    if (input_read == 'y' || input_read == 'Y') {
        return 1;
    } else if (input_read == 'n' || input_read == 'N') {
        return 2;
    } else {
        return 0;
    }
}

void view::InfoInit() {
    PrintLine("Done!");
}

void view::InfoNoDataCloseProgram() {
    PrintLine("No data to load. Closing program.");
}

void view::InfoLoadData() {
    Print("Loading data ... ");
}

void view::InfoReturnToMainMenu() {
    PrintLine();
    PrintLine("Returning to main menu"); 
}

void view::InfoFileNotSaved() {
    PrintLine("File not saved");
}

void view::InfoInvalidAnswer() {
    PrintLine("Invalid answer!");
}

void view::InfoFileSaved() {
    PrintLine("File saved");
}

void view::InfoErrorSavingFile() {
    PrintLine("Error saving file");
}

void view::InfoResult() {
    PrintLine("Result:");
}

void view::InfoNameNotFound() {
    PrintLine("Name not found");
}

void view::InfoDbnNotFound() {
    PrintLine("DBN not found");
}

void view::InfoEndProgram(){
    PrintLine();
    PrintLine("Closing program. Good bye!");
}

void view::InfoInvalidOption() {
    PrintLine("Invalid option! Try again.");
}

void view::MainMenu() {
    PrintLine();
    PrintLine("=======================");
    PrintLine("Choose new search type:");
    PrintLine("1) Search by name");
    PrintLine("2) Search by DBN");
    PrintLine("3) Quit program");
}

void view::MenuSearchByName() {
    PrintLine();
    Print("Search by name: ");
}

void view::MenuAskSaveFile() {
    PrintLine();
    PrintLine("Save results? (y/n) ");
}

void view::MenuSaveFile() {
    PrintLine("Type the destination file path: ");
}

void view::MenuSearchByDbn() {
    PrintLine();
    Print("Search by DBN: ");
}

void view::PrintResults(const std::vector<std::string> &header,
                        const std::vector<std::vector<std::string>> &results_list) {
    // InfoResult();
    PrintHeader(header);
	for (int i = 0; i < results_list.size(); i++) {
		for (int j = 0; j < results_list[i].size(); j++) {
            if (j) {
                Print(",");
            }
			Print(results_list[i][j]);
		}
		PrintLine();
	}
}

void view::PrintHeader(const std::vector<std::string> &header) {
	PrintLine();
	for (int k = 0; k < header.size(); k++) {
        if (k) {
            Print(",");
        }
		Print(header[k]);
	}
	PrintLine();
    PrintLine();
}

}  // namespace View
}  // namespace CppChallenge
