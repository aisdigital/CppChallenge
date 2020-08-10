#pragma once

#include <string>

class ResultData
{
public:
    ResultData(const std::string &DBN,
               const std::string &schoolName,
               const std::string &numberOfTestTakers,
               const std::string &criticalReadingMean,
               const std::string &mathematicsMean,
               const std::string &writingMean);

    ResultData(const ResultData &other) = default;

    ~ResultData() = default;

    bool operator<(const ResultData &other)
    {
        return schoolName < other.schoolName;
    }

    bool operator>(const ResultData &other)
    {
        return schoolName > other.schoolName;
    };

    std::string ToString() const;

    std::string DBN;
    std::string schoolName;
    std::string numberOfTestTakers;
    std::string criticalReadingMean;
    std::string mathematicsMean;
    std::string writingMean;
};