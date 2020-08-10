#pragma once

#include "ResultData.h"

#include <string>
#include <vector>
#include <map>

class ResultsContainer
{
public:
    ResultsContainer() = default;
    ~ResultsContainer() = default;

    bool Load(const std::string &path);
    static bool Save(const std::string &path, std::vector<ResultData> results);

    std::vector<ResultData> SearchByName(const std::string &name);
    std::vector<ResultData> SearchByDBN(const std::string &dbn);

private:
    void persistData(std::vector<ResultData> results);

    std::map<std::string, ResultData> datas;
};