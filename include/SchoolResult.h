#pragma once

#include <string>

class SchoolResult {
public:
    std::string dbn;
    std::string schoolName;
    unsigned int numberOfTestTakers;
    unsigned int criticalReadingMean;
    unsigned int mathematicsMean;
    unsigned int writingMean;

    friend std::ostream& operator<<(std::ostream& out, SchoolResult &result) {
        return out << "Results for " << result.schoolName << "(" << result.dbn << ")" << std::endl <<
               "Number of test takers: " << result.numberOfTestTakers << std::endl <<
               "Critical Reading Mean: " << result.criticalReadingMean << std::endl <<
               "Mathematics Mean: " << result.mathematicsMean << std::endl <<
               "Writing Mean: " << result.writingMean << std::endl;
    }
};