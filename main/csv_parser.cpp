
#include <fstream>
#include <sstream>

#include "csv_parser.hpp"

bool CSVParser::loadCSV(const std::string &path)
{
    std::ifstream file{path};
    if (file.is_open())
    {
        std::string line;
        std::string word;
        std::vector<std::string> row;

        while (std::getline(file, line))
        {
            row = parseRow(line);
            table.push_back(row);
        }
        return true;
    }
    else
    {
        return false;
    }
}

const CSVTable &CSVParser::getCSVTable() const
{
    return table;
}

bool CSVParser::writeCSVFile(const std::string &path, const CSVTable &table)
{
    std::ofstream file{path};
    if (file.is_open())
    {
        for (auto &row : table)
        {
            for (size_t i = 0; i < row.size(); i++)
            {
                file << row.at(i);
                if(i != row.size() - 1) file << ",";
            }
            file << "\n";
        }
        return true;
    }
    return false;
}

CSVRow CSVParser::parseRow(const std::string &row) const
{
    // Utility Constants
    static constexpr auto COMMA = ',';
    static constexpr auto QUOTE = '\"';
    enum class State
    {
        Unquoted,
        Quoted,
        DoubleQuoted
    };

    std::vector<std::string> cell{""};
    auto current_state = State::Unquoted; // We default the line as unquoted
    auto index = 0;

    // State machine
    // Process character by character to take into account
    // three cases possible on a CSV row:
    // 1. Normal unquoted strings
    // 2. Quoted strings with possible embedded commas
    // 3. Double quoted strings with possible embedded commnas
    for (auto character : row)
    {
        switch (current_state)
        {
        case State::Unquoted:
            switch (character)
            {
            case COMMA:
                cell.push_back("");
                ++index;
                break;
            case QUOTE:
                current_state = State::Quoted;
                break;
            default:
                cell[index].push_back(character);
                break;
            }
            break;
        case State::Quoted:
            switch (character)
            {
            case QUOTE:
                current_state = State::DoubleQuoted;
                break;
            default:
                cell[index].push_back(character);
                break;
            }
            break;
        case State::DoubleQuoted:
            switch (character)
            {
            case COMMA:
                cell.push_back("");
                current_state = State::Unquoted;
                ++index;
                break;
            case QUOTE:
                cell[index].push_back('"');
                current_state = State::Quoted;
                break;
            default:
                current_state = State::Unquoted;
                break;
            }
            break;
        }
    }
    return cell;
}
