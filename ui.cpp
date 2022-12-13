#include "ui.h"


void UI::printFilesMenu(const std::map<int, std::string> &filesMap)
{
    std::cout << "===============================================================" << std::endl;
    std::cout << std::setw(5) << "Please Select the File to Read:" << std::endl;
    std::cout << "===============================================================" << std::endl;
    for(const auto &file : filesMap)
    {
      std::cout << file.first << " - " << file.second << std::endl;
    }
    std::cout << "\n Selected File:  ";
    return;
}

void UI::printStartFileRead(const std::string &filePath)
{
    std::cout << "===============================================================" << std::endl;
    std::cout << "Reading " << filePath << std::endl;
    return;
}


void UI::printSATFilterMenu()
{
    std::cout << "===============================================================" << std::endl;
    std::cout << "Please Select a Valid Option:" << std::endl;
    std::cout << "1 - Search by DBN" << std::endl;
    std::cout << "2 - Search by School Name" << std::endl;
    std::cout << "3 - Exit" << std::endl;
    std::cout << "Input Option: ";
}

void UI::getOptionInput(int &optionValue)
{
    std::string strInput;
    getline(std::cin , strInput);
    {
      std::stringstream linestream(strInput);
      linestream >> optionValue;
    }

}

