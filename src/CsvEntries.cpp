#include "CsvEntries.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>

#include <sys/stat.h>

const char *CsvEntry::header = "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean";

CsvEntries CsvEntries::loadFromFile(std::string csvFileName)
{
    std::vector<CsvEntry> entries;
    std::ifstream csvFile(csvFileName);
    std::string line;
    std::getline(csvFile, line);
    while (std::getline(csvFile, line))
    {
        auto entry = CsvEntry::from(std::move(line));
        entries.push_back(entry);
    }
    return CsvEntries(std::move(entries));
}

CsvEntries::CsvEntries(std::vector<CsvEntry> entries) noexcept
    : entries{std::move(entries)}
{}

std::string CsvEntries::into() const
{
    auto csv = intoCsv();
    return csv.erase(csv.find_last_not_of(" \n\r\t")+1);
}

std::string CsvEntries::intoCsv() const
{
    std::stringstream out;
    for (auto entry : entries)
    {
        out << entry.intoCsv() << std::endl;
    }
    return out.str();
}

CsvEntry CsvEntries::lookupByDbn(const std::string &dbn) const
{
    auto result = std::find_if(
        entries.begin(),
        entries.end(),
        [dbn](const CsvEntry &entry)
        {
            return entry.dbn == dbn;
        }
    );
    if (result == entries.end())
    {
        throw NoEntryFound();
    }
    return *result;
}

std::string strToUpper(std::string s)
{
    std::string result;
    std::transform(s.begin(), s.end(), std::back_inserter(result), ::toupper);
    return result;
}

CsvEntries CsvEntries::lookupByNameAndSort(const std::string &schoolName) const
{
    std::vector<CsvEntry> result;
    std::copy_if(
        entries.begin(),
        entries.end(),
        std::back_inserter(result),
        [schoolName](const CsvEntry &entry)
        {
            return strToUpper(entry.schoolName)
                .find(strToUpper(schoolName)) != std::string::npos;
        }
    );
    std::sort(result.begin(),result.end());
    return CsvEntries(std::move(result));
}

bool CsvEntries::isEmpty() const
{
    return entries.size() == 0;
}

void CsvEntries::saveToFile(std::string csvFileName)
{
    std::ofstream csvFile("output/" + csvFileName);
    if (not csvFile.good())
    {
        // I don't know a good way to create directory in different operating systems
        system("mkdir output");
        csvFile = std::ofstream("output/" + csvFileName);
    }
    csvFile << CsvEntry::header << std::endl;
    csvFile << intoCsv();
}

CsvEntry::CsvEntry(std::string dbn, std::string schoolName, std::string otherInfo) noexcept
    : dbn{std::move(dbn)}
    , schoolName{std::move(schoolName)}
    , otherInfo{std::move(otherInfo)}
{}

bool CsvEntry::operator<(const CsvEntry &right)
{
    return this->schoolName < right.schoolName;
}

CsvEntry CsvEntry::from(std::string line)
{
    const std::regex csv_regex("^([^,]*),(\"([^\"]*)\"|([^,\"][^,]*)),(.*,.*,.*,.*)$");
    std::smatch csv_match;
    if (not std::regex_match(line, csv_match, csv_regex)) {
        throw std::runtime_error("Fail to load CSV, malformed file");
    }
    return CsvEntry(
        csv_match[1].str(),
        csv_match[3].str() + csv_match[4].str(),
        csv_match[5].str()
    );
}

std::string CsvEntry::into() const
{
    return intoCsv();
}

std::string CsvEntry::intoCsv() const
{
    std::stringstream out;
    out << dbn << ",";
    out << (schoolName.find(",") == std::string::npos? schoolName : '"' + schoolName + '"') << ",";
    out << otherInfo;
    return out.str();
}
