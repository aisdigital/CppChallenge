#include "application.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include "csv_parser.hpp"

void Application::run()
{
    static constexpr auto SEARCH_BY_NAME_CODE = "1";
    static constexpr auto SEARCH_BY_DBN_CODE = "2";
    static constexpr auto EXIT_CODE = "3";
    std::cout << "Challenge C++\n"
              << std::endl;

    std::string code{""}; // Using string as code to avoid cin locking.
    while (code != EXIT_CODE)
    {
        std::cout << "\n1. Search by school name\n";
        std::cout << "2. Search by DBN\n";
        std::cout << "3. Exit\n\n";

        std::cin >> code;
        if (code == SEARCH_BY_NAME_CODE)
        {
            optionSearchBySchoolName();
        }
        else if (code == SEARCH_BY_DBN_CODE)
        {
            optionSearchByDBN();
        }
        else if (code == EXIT_CODE)
        {
            std::cout << "Exiting program..."
                      << "\n\n";
        }
        else
        {
            std::cout << "Wrong option: " << code << "\n\n";
        }
    }
}

bool Application::setup(const std::string &filepath)
{
    if (!std::filesystem::is_directory("output"))
        std::filesystem::create_directory("output");

    std::ifstream file{filepath};
    if (file.is_open())
    {

        CSVParser parser;
        std::stringstream strStream;
        strStream << file.rdbuf();
        parser.loadCSV(strStream);
        levelResults.processCSVTable(parser.getCSVTable());
        return true;
    }
    return false;
}

void Application::optionSearchBySchoolName()
{
    std::string schoolName{};
    std::cout << "\n1. Search for term...: ";
    std::cin >> schoolName;
    auto subTable = levelResults.queryBySchoolName(schoolName);
    if (subTable.empty())
    {
        std::cout << "\nNo schools with term " << schoolName << " found.\n";
    }
    else
    {
        std::cout << "\n"
                  << subTable.size() << " schools found.\n\n";
        std::cout << "\nDBN | School Name | Number of Test Takers | Critical Reading Mean | Mathematics Mean | Writing Mean\n";

        for (auto &row : subTable)
        {
            for (const auto &cell : row)
            {
                std::cout << cell << "    ";
            }
            std::cout << "\n"
                      << std::endl;
        }
        std::string save{};
        std::cout << "\n Do you want to save this search to a file? yes or no \n";
        std::cin >> save;
        if (save == "yes")
        {
            std::cout << "\nPlease, inform the file name: ";
            std::string path{};
            std::cin >> path;
            path = "output\\" + path + ".csv";
            if (!CSVParser::writeCSVFile(path, subTable))
            {
                std::cout << "\nUnable to write file.\n";
            }
        }
        else if (save == "no")
        {
            std::cout << "\nReturning to main menu... \n";
        }
        else
        {
            std::cout << "\nWrong option: " << save << "\n\n";
        }
    }
}

void Application::optionSearchByDBN()
{
    std::string dbn;
    std::cout << "\n1. Search for DBN...: ";
    std::cin >> dbn;
    auto row = levelResults.queryByDBN(dbn);
    if (row.empty())
    {
        std::cout << "\n DBN " << dbn << " not found. \n";
    }
    else
    {
        std::cout << "\n\nDBN | School Name | Number of Test Takers | Critical Reading Mean | Mathematics Mean | Writing Mean\n";

        for (const auto &cell : row)
        {
            std::cout << cell << "    ";
        }
        std::cout << "\n"
                  << std::endl;
    }
}
