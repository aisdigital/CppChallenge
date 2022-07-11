#pragma once

#include <cstdint>
#include <string>

/**
 * School SAT Results
 *
 * @ref https://en.wikipedia.org/wiki/SAT
 */
class SchoolSatResult {
public:
  std::string DBN;
  std::string SchoolName;
  uint16_t TestTakesNumber = 0;
  uint16_t CriticalReadingMean = 0;
  uint16_t MathematicsMean = 0;
  uint16_t WritingMean = 0;
};
