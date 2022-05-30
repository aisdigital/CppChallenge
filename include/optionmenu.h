#ifndef OPTIONSELECTOR_H
#define OPTIONSELECTOR_H

#include <string>
#include <vector>

class DataEntry;

enum class OptionStates
{
    EXIT_SEARCH = 0,
    NAME_SEARCH,
    DBN_SEARCH,
};

class OptionMenu
{
    OptionStates m_optionSelected;

public:
    OptionMenu();

    void viewInitialMenu();

    void viewSubstringInputMenu();

    void viewDBNInputMenu();

    void viewSaveMenu();

    void viewFileSaveMenu();

    void viewDataEntries(const std::vector<DataEntry> &entries);

    void viewExitMenu();

    void readInitialOption();

    void readSearchTerm(std::string& searchTerm);

    bool readSaveOption();

    void readSaveFilename(std::string& filename);

    OptionStates getOptionSelected() const;
};

#endif // OPTIONSELECTOR_H
