#pragma once

#include "SchoolSatResult.h"

#include <sstream>

namespace Parser
{
    /**
     * Convert SchoolSatResult to the CSV String with the following format
     * "{DBN},{SchoolName},{TestTakersNumber},{CriticalReadingMean},{MathematicsMean},{WritingMean}"
     */
    static std::string ToString( const SchoolSatResult & schoolSatResult)
    {
        std::ostringstream ss;
        
        // Identification: {DBN},{SchoolName} 
        ss << schoolSatResult.DBN << ","
           << schoolSatResult.SchoolName << ",";
        
        if( schoolSatResult.TestTakesNumber != 0 )
        {
           ss << schoolSatResult.TestTakesNumber;
        }

        ss << ",";

        // {CriticalReadingMean}
        if( schoolSatResult.CriticalReadingMean != 0 )
        {
           ss << schoolSatResult.CriticalReadingMean;
        }

        ss << ",";

        // {MathematicsMean}
        if( schoolSatResult.MathematicsMean != 0 )
        {
           ss << schoolSatResult.MathematicsMean;
        }

        ss << ",";

        // {WritingMean} 
        if( schoolSatResult.WritingMean != 0 )
        {
           ss << schoolSatResult.WritingMean;
        }

        return ss.str();
    }

    static SchoolSatResult ToSchoolSatResult( const std::string & csvString)
    {
        SchoolSatResult schoolSatResult;
        return schoolSatResult;
    }
};