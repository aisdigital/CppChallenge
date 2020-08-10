#include "ResultData.h"

#include <sstream>

ResultData::ResultData(const std::string &DBN,
                       const std::string &schoolName,
                       const std::string &numberOfTestTakers,
                       const std::string &criticalReadingMean,
                       const std::string &mathematicsMean,
                       const std::string &writingMean)
    : DBN(DBN),
      schoolName(schoolName),
      numberOfTestTakers(numberOfTestTakers), 
      criticalReadingMean(criticalReadingMean),
      mathematicsMean(mathematicsMean),
      writingMean(writingMean)
{
}

std::string ResultData::ToString() const
{
  std::stringstream ss;
  ss << "DBN: " << DBN << std::endl;
  ss << "School Name: " << schoolName << std::endl;
  ss << "Number of Test Takers: " << numberOfTestTakers << std::endl;
  ss << "Critical Reading Mean: " << criticalReadingMean << std::endl;
  ss << "Mathematics Mean: " << mathematicsMean << std::endl;
  ss << "Writing Mean: " << writingMean << std::endl;

  return ss.str();
}