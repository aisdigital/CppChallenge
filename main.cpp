// Challenge C++ AISDigital

#include <iostream>
#include "CsvEntries.hpp"
#include "Ui.hpp"


int control(CsvEntries &entries)
{
    while (true)
    switch (Ui::mainMenu())
    {
        case MenuOptions::SearchByName:
        {
            auto schoolName = Ui::askSchoolName();
            auto schools = entries.lookupByNameAndSort(std::move(schoolName));
            if (schools.isEmpty())
            {
                Ui::printNotFound();
                continue;
            }
            bool shouldSave = Ui::printAndAskToSave(schools);
            if (shouldSave)
            {
                auto outFilename = Ui::askFilenameToSave();
                schools.saveToFile(outFilename);
            }
            continue;
        }
        case MenuOptions::SearchByDBN:
        {
            auto dbn = Ui::askDbn();
            try
            {
                auto school = entries.lookupByDbn(dbn);
                Ui::printEntry(school);
            }
            catch (const NoEntryFound &)
            {
                Ui::printNotFound();
            }
            continue;
        }
        case MenuOptions::Exit:
            return 0;
    }
}


int main(int argc, const char * argv[]) { 
    try
    {
        auto entries = CsvEntries::loadFromFile("input/SAT__College_Board__2010_School_Level_Results.csv");
        return control(entries);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
