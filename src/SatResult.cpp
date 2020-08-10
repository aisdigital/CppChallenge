
#include "SatResult.h"

std::string SatResult::toCsvLine() {
    return Dbn + ',' +
           SchoolName + ',' +
           NumberOfTestTakers + ',' +
           CriticalReadingMean + ',' +
           MathematicsMean + ',' +
           WritingMean;
}