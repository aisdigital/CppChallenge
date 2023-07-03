
#include <algorithm>
#include <iostream>
#include "level_results.hpp"


LevelResults::LevelResults(const CSVTable &table)
{
    processCSVTable(table);
}

void LevelResults::processCSVTable(const CSVTable &table)
{
    static constexpr auto LEVEL_RESULTS_ROW_SIZE = 6;

    for (auto &row : table)
    {
        if (row.size() == LEVEL_RESULTS_ROW_SIZE)
        {
            data.emplace(row[0], row);
        }
    }
}

CSVTable LevelResults::queryBySchoolName(const std::string &name) const
{
    static constexpr auto SCHOOL_NAME_POSITION = 1;
    
    CSVTable table;
    auto current_itr = data.begin();
    auto is_name = [&](auto& row) { return row.second[SCHOOL_NAME_POSITION].find(name) != std::string::npos; };
    while ((current_itr = std::find_if(current_itr, std::end(data), is_name)) != std::end(data))
    {
        table.push_back(current_itr->second);
        current_itr++;
    }
    std::sort(std::begin(table), std::end(table), [&](const auto& a, const auto&b){ return a[SCHOOL_NAME_POSITION] < b[SCHOOL_NAME_POSITION]; });
    return table;
}

CSVRow LevelResults::queryByDBN(const std::string &dbn) const
{
    CSVRow row;
    if (!data.empty())
    {
        auto search = data.find(dbn);
        if (search != data.end())
        {
            row = search->second;
        }
    }
    return row;
}
