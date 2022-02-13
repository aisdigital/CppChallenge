#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//! Compare two entries school names, used to sort an entries vector
struct CompareEntriesSchoolNames
{
    inline bool operator() (const Entry& firstEntry, const Entry& secondEntry)
    {
        return (firstEntry.getSchoolName() < secondEntry.getSchoolName());
    }
};

//! Search CSV by School Name and show on the screen the results sorted by name.
/*!
    \param dataPointer A pointer to the CSV stored in memory.
    \param schoolName School Name to look up in CSV stored in memory.
    \param entriesSchoolName A pointer to the resulting entries objects of the searchBySchoolName query.
    \return
*/
void searchBySchoolName(const std::vector<std::vector<std::string>>& dataPointer, std::string schoolName, std::vector<Entry>& entriesSchoolName);

//! Search CSV by DBN and show the matching entry on the screen.
/*!
    \param dataPointer A pointer to the CSV stored in memory.
    \param DBN Unique identifier of an entry in the CSV stored in memory.
    \param entryDBN A pointer to the resulting entry object of the searchByDBN query.
    \return 
*/
void searchByDBN(const std::vector<std::vector<std::string>>& dataPointer, const std::string DBN, Entry& entryDBN);
