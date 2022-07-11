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
  SchoolSatResult() {
    this->DBN = "";
    this->SchoolName = "";
    this->TestTakesNumber = 0;
    this->CriticalReadingMean = 0;
    this->MathematicsMean = 0;
    this->WritingMean = 0;
  };

  SchoolSatResult(const std::string &dbn, const std::string &schoolName,
                  uint16_t testTakesNumber, uint16_t criticalReadingMean,
                  uint16_t mathematicsMean, uint16_t writingMean) {
    this->DBN = dbn;
    this->SchoolName = schoolName;
    this->TestTakesNumber = testTakesNumber;
    this->CriticalReadingMean = criticalReadingMean;
    this->MathematicsMean = mathematicsMean;
    this->WritingMean = writingMean;
  };

  std::string DBN;
  std::string SchoolName;
  uint16_t TestTakesNumber = 0;
  uint16_t CriticalReadingMean = 0;
  uint16_t MathematicsMean = 0;
  uint16_t WritingMean = 0;
};
