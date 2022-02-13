#include "../include/storage.hpp"

std::vector<std::string> readCSVRow(const std::string &row)
{
    //! assume that the fields are unquoted
    CSVState state = CSVState::UnquotedField;
    //! create vector to store fields in row
    std::vector<std::string> fields{""};
    //! index of the current field
    size_t i = 0;
    //! loop through the row char by char
    for (char c : row)
    {
        switch (state)
        {
        case CSVState::UnquotedField:
            switch (c)
            {
            //! found opening quotes on field
            case '"':
                state = CSVState::QuotedField;
                break;
            //! end of field, increment counter
            case ',':
                fields.push_back("");
                i++;
                break;
            //! add char to current field
            default:
                fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedField:
            switch (c)
            {
            //! found closing quotes on field
            case '"':
                state = CSVState::UnquotedField;
                break;
            //! add char to current field
            default:
                fields[i].push_back(c);
                break;
            }
            break;
        }
    }
    return fields;
}

std::vector<std::vector<std::string>> readCSV(std::istream &in)
{
    std::vector<std::vector<std::string>> table;
    std::string row;
    //! loop through file
    while (!in.eof())
    {
        //! convert line stream into string
        std::getline(in, row);
        if (in.bad() || in.fail())
        {
            break;
        }
        //! obtain fields of line
        auto fields = readCSVRow(row);
        //! add fields to table
        table.push_back(fields);
    }
    return table;
}
