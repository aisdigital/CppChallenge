#include "Ui.hpp"

#include "CsvEntries.hpp"

MenuOptions Ui::mainMenu() noexcept
{
    std::string chosen;
    while(true)
    {
        std::cout
            << "Choose an option:" << std::endl
            << "1. Search by Name" << std::endl
            << "2. Search by DBN" << std::endl
            << "3. Exit program" << std::endl;
        std::cin >> chosen;
        if (chosen == "1")
            return MenuOptions::SearchByName;
        if (chosen == "2")
            return MenuOptions::SearchByDBN;
        if (chosen == "3")
            return MenuOptions::Exit;
    }
}


std::string Ui::askSchoolName() noexcept
{
    std::string schoolName;
    std::cout << "Type the name of the school:" << std::endl;
    std::cin >> schoolName;
    return schoolName;
}

std::string Ui::askDbn() noexcept
{
    std::string dbn;
    std::cout << "Type the DBN of the school:" << std::endl;
    std::cin >> dbn;
    return dbn;
}

std::string Ui::askFilenameToSave() noexcept
{
    std::string filename;
    std::cout << "Type the output filename:" << std::endl;
    std::cin >> filename;
    return filename;
}

bool Ui::printAndAskToSave(const PrintableEntry &entry)
{
    std::string shouldSave;
    std::cout << entry.into() << std::endl;
    do
    {
        std::cout << "Do you want to save to a file? (yes or no)" << std::endl;
        std::cin >> shouldSave;
    }
    while (shouldSave != "yes" and shouldSave != "no");
    return shouldSave == "yes";
}

void Ui::printEntry(const PrintableEntry &entry)
{
    std::cout << entry.into() << std::endl;
}

void Ui::printNotFound()
{
    std::cout << "No entries found" << std::endl;
}
