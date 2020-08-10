#include "Menu.h"

#include <algorithm>
#include <iostream>

int Menu::Run()
{
    resultsContainer.Load("./input/SAT__College_Board__2010_School_Level_Results.csv");

    bool keep_running = true;

    while (keep_running)
    {
        switch (menu())
        {
        case SEARCH_BY_SCHOOL_NAME:
        {
            searchByName();
        }
        break;

        case SEARCH_BY_DBN:
        {
            searchByDBN();
        }
        break;

        case EXIT:
        {
            std::cout << "Bye!" << std::endl;
            keep_running = false;
        }
        break;

        default:
        {
            std::cout << "Invalid Option" << std::endl;
        }
        break;
        }
    }

    return 0;
}

int Menu::menu()
{
    std::cout << "\n Challenge C++ \n"
              << std::endl;
    std::cout << "1. Search by Name" << std::endl;
    std::cout << "2. Search by DBN" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "\nEnter one of the following: 1, 2, or 3: ";

    int answer = 0;
    std::cin >> answer;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Invalid Option." << std::endl;

        answer = 0;
    }

    return answer;
}

// Search by name: It will ask the user to input a string and it will search by **School Name** and show on the screen the results(results should be sorted by name).
// Asking if the user wants to save the results on a **csv** file where if yes ask the file name, that will be stored in a directory called `output`,
void Menu::searchByName()
{
    std::string name;
    std::cout << "Insert School name to search: ";
    std::cin >> name;

    const auto results = resultsContainer.SearchByName(name);
    printResults(results);

    while (true)
    {
        std::string save;
        std::cout << " Do you want to save the results? [yes/no] : ";
        std::cin >> save;

        std::transform(save.begin(), save.end(), save.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (save == "yes")
        {
            break;
        }

        if (save == "no")
        {
            return;
        }

        std::cout << "Invalid Answer!" << std::endl;
    }

    std::string filename;
    std::cout << "Please insert the filename: ";
    std::cin >> filename;

    ResultsContainer::Save(filename, results);

    std::cout << "Results saved to ./output/" << filename << std::endl ;
}

// Search by DBN: It will ask the user to input a string and it will search by **DBN** and show on the screen the result.
void Menu::searchByDBN()
{
    std::string dbn;
    std::cout << "Insert DBN to search: ";
    std::cin >> dbn;

    const auto results = resultsContainer.SearchByDBN(dbn);
    printResults(results);
}

void Menu::printResults(const std::vector<ResultData> &results)
{
    if (results.empty())
    {
        std::cout << "No data found" << std::endl;
        return;
    }

    for (const auto &result : results)
    {
        std::cout << result.ToString() << std::endl;
    }
}