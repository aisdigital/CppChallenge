#pragma once

#include <cstdint>
#include <string>

/**
 * School SAT Results
 *
 * @ref https://en.wikipedia.org/wiki/SAT
 */
class SchoolSatResult
{
public:
    std::string DBN;
    std::string SchoolName;
    uint16_t TestTakesNumber;
    uint16_t CriticalReadingMean;
    uint16_t MathematicsMean;
    uint16_t WritingMean;
};