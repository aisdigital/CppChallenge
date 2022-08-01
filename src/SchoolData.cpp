#include "SchoolData.hpp"

#include <sstream>

//---------------------------------------------------------------------------------------------

SchoolData::SchoolData(
  const std::string& _dbn,
  const std::string& _schoolName,
  const std::string& _numberOfTestTakers,
  const std::string& _criticalReadingMean,
  const std::string& _mathematicsMean,
  const std::string& _writingMean
)
  : 
  dbn(_dbn),
  schoolName(_schoolName),
  numberOfTestTakers(_numberOfTestTakers),
  criticalReadingMean(_criticalReadingMean),
  mathematicsMean(_mathematicsMean),
  writingMean(_writingMean)
{
}

//---------------------------------------------------------------------------------------------

SchoolData::SchoolData(
  const SchoolData& other
)
{
  dbn = other.dbn;
  schoolName = other.schoolName;
  numberOfTestTakers = other.numberOfTestTakers;
  criticalReadingMean = other.criticalReadingMean;
  mathematicsMean = other.mathematicsMean;
  writingMean = other.writingMean;
}

//---------------------------------------------------------------------------------------------

bool SchoolData::operator<(
  const SchoolData& other
)
{
  return schoolName < other.schoolName;
}

//---------------------------------------------------------------------------------------------

bool SchoolData::operator>(
  const SchoolData& other
)
{
  return schoolName > other.schoolName;
}

//---------------------------------------------------------------------------------------------

std::string SchoolData::ToString() const
{
  std::stringstream stream;
  stream << "DBN: " << dbn << std::endl;
  stream << "School Name: " << schoolName << std::endl;
  stream << "Number of Test Takers: " << numberOfTestTakers << std::endl;
  stream << "Critical Reading Mean: " << criticalReadingMean << std::endl;
  stream << "Mathematics Mean: " << mathematicsMean << std::endl;
  stream << "Writing Mean: " << writingMean << std::endl;
  return stream.str();
}

//---------------------------------------------------------------------------------------------

const std::string& SchoolData::DBN() const
{
  return dbn;
}

//---------------------------------------------------------------------------------------------


const std::string& SchoolData::SchoolName() const
{
  return schoolName;
}

//---------------------------------------------------------------------------------------------

const std::string& SchoolData::NumberOfTestTakers() const
{
  return numberOfTestTakers;
}

//---------------------------------------------------------------------------------------------

const std::string& SchoolData::CriticalReadingMean() const
{
  return criticalReadingMean;
}

//---------------------------------------------------------------------------------------------

const std::string& SchoolData::MathematicsMean() const
{
  return mathematicsMean;
}

//---------------------------------------------------------------------------------------------

const std::string& SchoolData::WritingMean() const
{
  return writingMean;
}

//---------------------------------------------------------------------------------------------
