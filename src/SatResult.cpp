#include "SatResult.h"

std::string SatResult::toCsvLine() const {
    auto line = Dbn + ',';

    if (SchoolName.find(',') == std::string::npos) {
        line += SchoolName + ',';
    } else {
        line += "\"" + SchoolName + "\",";
    }

    line += NumberOfTestTakers + ',' +
            CriticalReadingMean + ',' +
            MathematicsMean + ',' +
            WritingMean;

    return line;
}
