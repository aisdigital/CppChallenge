#include "SchoolDataMap.hpp"

#include <fstream>
#include <iostream>

#include <direct.h>
#include <sys/stat.h>

//---------------------------------------------------------------------------------------------

bool SchoolDataMap::Load(
  const std::string& inputPath
)
{
  try 
  {
    io::CSVReader<6, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '"'>> csv(inputPath.c_str());

    csv.read_header(
      io::ignore_missing_column, 
      "DBN", 
      "School Name", 
      "Number of Test Takers", 
      "Critical Reading Mean", 
      "Mathematics Mean", 
      "Writing Mean"
    );

    std::string DBN;
    std::string schoolName;
    std::string numberOfTestTakers;
    std::string criticalReadingMean;
    std::string mathematicsMean;
    std::string writingMean;

    while (csv.read_row(DBN, schoolName, numberOfTestTakers, criticalReadingMean, mathematicsMean, writingMean)) 
    {
      std::shared_ptr<SchoolData> data = std::make_shared<SchoolData>(DBN, schoolName, numberOfTestTakers, criticalReadingMean, mathematicsMean, writingMean);
      schoolDataMap[DBN] = data;
    }
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  return true;
}

//---------------------------------------------------------------------------------------------

bool SchoolDataMap::Save(
  const std::string& fileName,
  const std::vector<std::shared_ptr<SchoolData>>& schoolsData
) const
{
  CreateOutputFolder();

  std::fstream output;
  try
  {
    output.open(outputPath + fileName + ".csv", std::ios::out);

    output
      << "DBN, School Name, Number of Test Takers,"
      << "Critical Reading Mean, Mathematics Mean, Writing Mean"
      << std::endl;

    for (const std::shared_ptr<SchoolData> data : schoolsData)
    {
      output 
        << data->DBN() << ","
        << data->SchoolName() << ","
        << data->NumberOfTestTakers() << ","
        << data->CriticalReadingMean() << ","
        << data->MathematicsMean() << ","
        << data->WritingMean() << std::endl;
    }

    output.close();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return false;
  }

  return true;
}

//---------------------------------------------------------------------------------------------

void SchoolDataMap::CreateOutputFolder() const
{
  struct stat info;
  const bool folderNotFound = stat(outputPath.c_str(), &info) != 0;
  if (folderNotFound)
  {
    mkdir(outputPath.c_str());
  }
}

//---------------------------------------------------------------------------------------------

std::vector<std::shared_ptr<SchoolData>> SchoolDataMap::SeachBySchoolName(
  const std::string& schoolName
)
{
  std::vector<std::shared_ptr<SchoolData>> schoolsFound;
  
  for (auto data : schoolDataMap) {
    if (data.second->SchoolName().find(schoolName) != std::string::npos) {
      schoolsFound.push_back(data.second);
    }
  }

  auto compare = [](std::shared_ptr<SchoolData> a, std::shared_ptr<SchoolData> b)
  {
    return *a < *b;
  };

  std::sort(schoolsFound.begin(), schoolsFound.end(), compare);

  return schoolsFound;
}

//---------------------------------------------------------------------------------------------

std::vector<std::shared_ptr<SchoolData>> SchoolDataMap::SeachBySchoolDBN(
  const std::string& schoolDBN
)
{
  std::vector<std::shared_ptr<SchoolData>> schoolsFound;
  
  if (schoolDataMap.find(schoolDBN) != schoolDataMap.end()) {
    schoolsFound.push_back(schoolDataMap[schoolDBN]);
  }
  
  return schoolsFound;
}

//---------------------------------------------------------------------------------------------
