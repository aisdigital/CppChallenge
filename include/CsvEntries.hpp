#pragma once

#include <map>
#include <string>
#include <vector>

#include <Ui.hpp>

struct NoEntryFound: public std::runtime_error
{
    NoEntryFound() : std::runtime_error{"No entry found"}
    {}
};

struct CsvEntry: public PrintableEntry {
    virtual std::string into() const override;
    virtual ~CsvEntry() = default;
    
    static const char *header;
    static CsvEntry from(std::string line);
    std::string intoCsv() const;
    
    explicit CsvEntry(
        std::string dbn,
        std::string schoolName,
        std::string otherInfo
    ) noexcept;
    
    bool operator<(const CsvEntry &right);

    std::string dbn;
    std::string schoolName;
    std::string otherInfo;
};

struct CsvEntries: public PrintableEntry 
{
    virtual std::string into() const override;
    virtual ~CsvEntries() = default;
    
    explicit CsvEntries(std::vector<CsvEntry> entries) noexcept;
    static CsvEntries loadFromFile(std::string csvEntries);
    
    CsvEntry lookupByDbn(const std::string &dbn) const;
    CsvEntries lookupByNameAndSort(const std::string &schoolName) const;
    bool isEmpty() const;
    
    void saveToFile(std::string csvEntries);
    std::string intoCsv() const;
    
    const std::vector<CsvEntry> entries;
};
