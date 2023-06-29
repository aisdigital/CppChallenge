

#include "csv_parser.hpp"
#include <fstream>

void CSVParser::loadCSV(std::stringstream& stream)
{

    std::string line;
    std::string word;
    std::vector<std::string> row;

    while (std::getline(stream, line))
    {
        {
            row = parseRow(line);
            data.push_back(row);
        }
    }
}

const CSVTable &CSVParser::getCSVTable() const
{
    return data;
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
                if(i != row.size() - 1)
                { 
                    file << ",";
                }
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
        NonQuoted,
        Quoted,
        DoubleQuoted
    };

    std::vector<std::string> cell{""};
    auto current_state = State::NonQuoted; // We default the line as non-quoted
    auto index = 0;

    // State machine
    // Process character by character to take into account
    // three cases possible on a CSV row:
    // 1. Normal non-quoted strings
    // 2. Quoted strings with possible embedded commas
    // 3. Double quoted strings with possible embedded commnas
    for (auto character : row)
    {
        switch (current_state)
        {
        case State::NonQuoted:
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
                current_state = State::NonQuoted;
                ++index;
                break;
            case QUOTE:
                cell[index].push_back('"');
                current_state = State::Quoted;
                break;
            default:
                current_state = State::NonQuoted;
                break;
            }
            break;
        }
    }
    return cell;
}


