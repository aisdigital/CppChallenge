#pragma once

#include <string>
#include <ostream>
#include <iomanip>

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
        out << std::string(150, '-') << std::endl
            << "|" << std::string(40, ' ') << "School Name" << std::string(40, ' ') << "|"
            << " Test Takers | Critical Reading | Mathematics | Writing |" << std::endl
            << std::string(150, '-') << std::endl;

        for (auto &item : results) {
            out << "|" << std::setw(91) << std::left << item.schoolName
                << "|" << std::setw(13) << std::left << (item.numberOfTestTakers.empty() ? "-" : item.numberOfTestTakers)
                << "|" << std::setw(18) << std::left << (item.criticalReadingMean.empty() ? "-" : item.criticalReadingMean)
                << "|" << std::setw(13) << std::left << (item.mathematicsMean.empty() ? "-" : item.mathematicsMean)
                << "|" << std::setw(9) << std::left << (item.writingMean.empty() ? "-" : item.writingMean)
                << "|" << std::endl;
        }
        
        out << std::string(150, '-') << std::endl;
        return out;        
    }
};