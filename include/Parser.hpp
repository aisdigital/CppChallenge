#pragma once

#include "SchoolSatResult.h"

#include <sstream>

namespace Parser
{
    static std::string ToString( const SchoolSatResult & schoolSatResult)
    {
        std::ostringstream ss;
        
        ss << schoolSatResult.DBN << ","
           << schoolSatResult.SchoolName << ","
           << schoolSatResult.TestTakesNumber << ","
           << schoolSatResult.CriticalReadingMean << ","
           << schoolSatResult.MathematicsMean << ","
           << schoolSatResult.WritingMean;

        return ss.str();
    }

    static SchoolSatResult ToSchoolSatResult( const std::string & csvString)
    {
        SchoolSatResult schoolSatResult;
        return schoolSatResult;
    }
};