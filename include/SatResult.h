#pragma once

#include <string>

class SatResult {
public:
    std::string schoolName;
    std::string numberOfTestTakers;
    std::string criticalReadingMean;
    std::string mathematicsMean;
    std::string writingMean;

    friend std::ostream& operator<<(std::ostream& out, SatResult &entry) {
        return out << "SAT Results for \"" << entry.schoolName << "\"" << std::endl
                   << "----------------------------------------------------------------------" << std::endl
                   << "Number of test takers: " << entry.numberOfTestTakers << std::endl
                   << "Critical Reading Mean: " << entry.criticalReadingMean << std::endl
                   << "Mathematics Mean: " << entry.mathematicsMean << std::endl
                   << "Writing Mean: " << entry.writingMean << std::endl;
    }
};