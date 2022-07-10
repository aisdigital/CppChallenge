#include "FileUtils.hpp"
#include "Parser.hpp"

#include <gtest/gtest.h>

TEST(FileUtils, ReadCSV) {

  const std::string inputfile = "input/SAT__College_Board__2010_School_Level_Results.csv";
  const std::string fileHeader = "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean";
  const std::string csvString = "01M292,Henry Street School for International Studies ,31,391,425,385";

  const std::vector<std::string> buffer = FileUtils::ReadCSV(inputfile);

  EXPECT_STREQ(buffer[0].c_str(), fileHeader.c_str());
  EXPECT_STREQ(buffer[1].c_str(), csvString.c_str());
}

TEST(SchoolSatResult, ModelInitialization) {
  const SchoolSatResult schoolSatResult;

  EXPECT_EQ(schoolSatResult.DBN,"");
  EXPECT_EQ(schoolSatResult.SchoolName,"");
  EXPECT_EQ(schoolSatResult.TestTakesNumber,0);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean,0);
  EXPECT_EQ(schoolSatResult.MathematicsMean,0);
  EXPECT_EQ(schoolSatResult.MathematicsMean,0);
}

TEST(Parser, ToSchoolSatResult) {
  const std::string csvString = "01M292,Henry Street School for International Studies ,31,391,425,385";

  const SchoolSatResult schoolSatResult = Parser::ToSchoolSatResult(csvString);

  EXPECT_EQ(schoolSatResult.DBN,"01M292");
  EXPECT_EQ(schoolSatResult.SchoolName,"Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResult.TestTakesNumber,31);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean,391);
  EXPECT_EQ(schoolSatResult.MathematicsMean,425);
  EXPECT_EQ(schoolSatResult.MathematicsMean,385);
}

TEST(Parser, CSVResultToString) {
  SchoolSatResult schoolSatResult;
  schoolSatResult.DBN = "01M292";
  schoolSatResult.SchoolName = "Henry Street School for International Studies ";
  schoolSatResult.TestTakesNumber = 31;
  schoolSatResult.CriticalReadingMean = 391;
  schoolSatResult.MathematicsMean = 425;
  schoolSatResult.WritingMean = 385;

  const std::string expectedCsvString = "01M292,Henry Street School for International Studies ,31,391,425,385";

  const std::string csvString = Parser::ToString(schoolSatResult);

  EXPECT_EQ(csvString,expectedCsvString);
}

TEST(Parser, CSVEmptyResultToString) {
  SchoolSatResult schoolSatResult;
  schoolSatResult.DBN = "19K639";
  schoolSatResult.SchoolName = "Brooklyn Lab School ";

  const std::string expectedCsvString = "19K639,Brooklyn Lab School ,,,,";

  const std::string csvString = Parser::ToString(schoolSatResult);

  EXPECT_EQ(csvString,expectedCsvString);
}


TEST(Parser, CSVZeroGradesResultToString) {
  SchoolSatResult schoolSatResult;
  schoolSatResult.DBN = "19K639";
  schoolSatResult.SchoolName = "Brooklyn Lab School ";
  schoolSatResult.TestTakesNumber = 0;
  schoolSatResult.CriticalReadingMean = 0;
  schoolSatResult.MathematicsMean = 0;
  schoolSatResult.WritingMean = 0;

  const std::string expectedCsvString = "19K639,Brooklyn Lab School ,,,,";

  const std::string csvString = Parser::ToString(schoolSatResult);

  EXPECT_EQ(csvString,expectedCsvString);
}