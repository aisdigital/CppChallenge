#include <istream>
#include <string>
#include <vector>

//! Enum for quoted fields treatment in CSV file.
enum class CSVState
{
    UnquotedField,
    QuotedField
};

//! Read a row of a given CSV file.
/*!
    \param row Pointer to a row in a CSV file.
    \return Vector containing the fields of a row in a row in a CSV file.
*/
std::vector<std::string> readCSVRow(const std::string& row);

//! Read a CSV file and store it in memory using a table format.
/*!
    \param in Pointer to CSV file.
    \return CSV data in a table format.
*/
std::vector<std::vector<std::string>> readCSV(std::istream& in);
