#include <algorithm>
#include "../include/output.hpp"
#include "../include/query.hpp"

void searchBySchoolName(const std::vector<std::vector<std::string>>& dataPointer, std::string schoolName, std::vector<Entry>& entriesSchoolName)
{
    bool schoolFound = false;
    //! loop through School Name rows, skipping header row in search, with complexity O(n)
    for (int i = 1; i < dataPointer.size(); i++)
    {
        //! if name in School Name column (second column in the CSV file) contains schoolName
        if (dataPointer[i][1].find(schoolName) != std::string::npos)
        {
            //! save query result in entryDBN argument
            entriesSchoolName.push_back(Entry(dataPointer[i]));
            //! set schoolFound flag to true
            schoolFound = true;
        }
    }
    //! schoolName found on the School Name column
    if (schoolFound)
    {
        //! order array by school name
        std::sort(entriesSchoolName.begin(), entriesSchoolName.end(), CompareEntriesSchoolNames());
        std::cout << entriesSchoolName.size() << " entries with School Name containing " << schoolName << " found!"
                  << std::endl;
        //! print ordered array
        for (int i = 0; i < entriesSchoolName.size(); i++)
        {
            std::cout << "\n" << (i + 1) << " of " << entriesSchoolName.size() << " Entry details:"
                      << std::endl;
            entriesSchoolName[i].printEntry();
        }
    }
    //! none of the School Name entries contains schoolName
    else
    {
        std::cout << "\nNo School Name containing " << schoolName << " found!"
                  << std::endl;
    }
    return;
}

void searchByDBN(const std::vector<std::vector<std::string>>& dataPointer, const std::string DBN, Entry& entryDBN)
{
    //! loop through School Name rows, skipping header row in search, with complexity O(n)
    for (int i = 1; i < dataPointer.size(); i++)
    {
        //! if schoolName is found on the School Name column (first column in the CSV file)
        if (DBN.compare(dataPointer[i][0]) == 0)
        {
            std::cout << "\nMatching DBN found! Entry details:"
                      << std::endl;
            //! save query result in entryDBN argument
            entryDBN = Entry(dataPointer[i]);
            entryDBN.printEntry();
            return;
        }
    }
    //! no schoolName is found on the School Name column
    std::cout << "\nNo matching DBN found!"
              << std::endl;
    return;
}
