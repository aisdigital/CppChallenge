
#include <map>
#include <string>
#include <vector>

struct CsvEntry {
    const char *header = "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean";
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

struct CsvEntries
{
    explicit CsvEntries(std::vector<CsvEntry> entries) noexcept;
    static CsvEntries loadFromFile(std::string csvEntries);
    
    CsvEntry lookupByDbn(std::string dbn) const;
    CsvEntries lookupByName(std::string schoolName) const;
    
    std::string into() const;
    
    const std::vector<CsvEntry> entries;
};
