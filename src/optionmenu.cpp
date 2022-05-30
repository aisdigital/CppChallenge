#include "../include/optionmenu.h"

#include <iostream>
#include <string>

#include "../include/dataentry.h"

OptionStates OptionMenu::getOptionSelected() const
{
    return m_optionSelected;
}

OptionMenu::OptionMenu() :
    m_optionSelected(OptionStates::EXIT_SEARCH)
{

}

void OptionMenu::viewInitialMenu()
{
    std::cout << "---------------------------------------------------------------------------------" << std::endl
              << " Please select one of the two options below by pressing the number and then enter:" << std::endl
              << "---------------------------------------------------------------------------------" << std::endl
              << " 1 - Search by Name : It will search for entries of a school name." << std::endl
              << " 2 - Search by DBN  : It will search for entries with a DBN string." << std::endl
              << " 3[DEFAULT] - Exit  : 3 or any other input will exit the program." << std::endl
              << "---------------------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewSubstringInputMenu()
{
    std::cout << "---------------------------------------------------------------------------------" << std::endl
              << "    Please write below the school name (or term) to be searched:" << std::endl
              << "---------------------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewDBNInputMenu()
{
    std::cout << "-------------------------------------------------------------------" << std::endl
              << "Please write below the exact DBN value to be searched:" << std::endl
              << "-------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewSaveMenu()
{
    std::cout << "-------------------------------------------------------------------" << std::endl
              << "Please select one of the two options below and then enter: " << std::endl
              << "-------------------------------------------------------------------" << std::endl
              << " yes or 'y'          - Save results: It will save the entries of " << std::endl
              << "                       the chosen school name in a CSV file." << std::endl
              << " no 'n' [DEFAULT]     - NOT Save results  : It will end the program." << std::endl
              << "-------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewFileSaveMenu()
{
    std::cout << "-------------------------------------------------------------------" << std::endl
              << "Please write the name of the file to be saved. (Extension CSV):" << std::endl
              << "-------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewDataEntries(const std::vector<DataEntry> &entries)
{
    std::cout << "-------------------------------------------------------------------" << std::endl
              << "      Searched Schools:" << std::endl
              << "-------------------------------------------------------------------"
              << std::endl;
    if (!entries.empty()) {
        std::cout << "DBN,"
                     "School Name,"
                     "Number of Test Takers,"
                     "Critical Reading Mean,"
                     "Mathematics Mean,"
                     "Writing Mean"
                  << std::endl;
        for (const auto& entry : entries) {
            std::cout << entry << std::endl;
        }
    } else {
        std::cout << "Sorry! No schools were found!" << std::endl;
    }
    std::cout << "-------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::viewExitMenu()
{
    std::cout << "---------------------------------------------------------------------------------" << std::endl
              << "    Exiting Program ... " << std::endl
              << "---------------------------------------------------------------------------------"
              << std::endl;
}

void OptionMenu::readInitialOption()
{
    int initialOption;
    std::cin >> initialOption;
    switch (initialOption) {
    case 1:
        m_optionSelected = OptionStates::NAME_SEARCH;
        break;
    case 2:
        m_optionSelected = OptionStates::DBN_SEARCH;
        break;
    case 3:
    default:
        m_optionSelected = OptionStates::EXIT_SEARCH;
        break;
    }
}

void OptionMenu::readSearchTerm(std::string &searchTerm)
{
    std::cin >> searchTerm;
}

bool OptionMenu::readSaveOption()
{
    std::string saveOption;
    std::cin >> saveOption;
    return (saveOption == "yes" || saveOption == "y");
}

void OptionMenu::readSaveFilename(std::string &filename)
{
    std::cin >> filename;
}
