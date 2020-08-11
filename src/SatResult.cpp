#include "SatResult.h"

std::string SatResult::toCsvLine() const {
    return Dbn + ',' +
           SchoolName + ',' +
           NumberOfTestTakers + ',' +
           CriticalReadingMean + ',' +
           MathematicsMean + ',' +
           WritingMean;
}
