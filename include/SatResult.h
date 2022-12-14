#pragma once

#include <string>
#include <ostream>

class SatResult {
public:
    std::string schoolName;
    std::string numberOfTestTakers;
    std::string criticalReadingMean;
    std::string mathematicsMean;
    std::string writingMean;

    friend std::ostream& operator<<(std::ostream& out, SatResult &result) {
        return out << result.schoolName << ','
                   << result.numberOfTestTakers << ','
                   << result.criticalReadingMean << ','
                   << result.mathematicsMean << ','
                   << result.writingMean << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, std::vector<SatResult> &results) {
        out << "School Name, Test Takers, Critical Reading Mean, Mathematics Mean, Writing Mean" << std::endl;
        for (auto &item : results) {
            out << item;
        }
        return out;
    }
};