#pragma once

#include "ResultsContainer.h"

#include <vector>

class Menu
{
    public:
    Menu() =default;
    ~Menu() =default;

    enum MenuOptions
    {
        SEARCH_BY_SCHOOL_NAME = 1,
        SEARCH_BY_DBN = 2,
        EXIT = 3,
    };

    int Run();

private:
    int menu();
    void writeData();
    void searchByName();
    void searchByDBN();
    void printResults(const std::vector<ResultData>& results);

    ResultsContainer resultsContainer;
};