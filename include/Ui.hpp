#pragma once

#include <iostream>

enum class MenuOptions
{
    SearchByName,
    SearchByDBN,
    Exit,
};

class PrintableEntry
{
public:
    virtual std::string into() const = 0;
    virtual ~PrintableEntry() = default;
};

class Ui
{
public:
    static MenuOptions mainMenu() noexcept;
    static std::string askSchoolName() noexcept;
    static std::string askDbn() noexcept;
    static std::string askFilenameToSave() noexcept;
        
    static bool printAndAskToSave(const PrintableEntry &entry);
    static void printEntry(const PrintableEntry &entry);
    static void printNotFound();
private:
};
