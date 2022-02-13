#include <iostream>
#include <limits>
#include <string>
#include "../include/Entry.hpp"

//! Save the results of a query to a CSV file in the /output directory using a given file name
/*!
    \param schoolName School Name to look up in CSV stored in memory.
    \param entriesSchoolName A pointer to the resulting entries objects of the searchBySchoolName query.
    \param DBN Unique identifier of an entry in the CSV stored in memory.
    \param entryDBN A pointer to the resulting entry object of the searchByDBN query.
    \return 
*/
void saveCSVOutput(const std::string schoolName, const std::vector<Entry>& entriesSchoolName, const std::string DBN, const Entry& entryDBN);
