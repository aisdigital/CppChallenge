#include <gtest/gtest.h>

#include "FileUtils.hpp"
#include "Parser.hpp"

TEST(SchoolSatResult, ModelInitialization) {
  const SchoolSatResult schoolSatResult;

  EXPECT_EQ(schoolSatResult.DBN, "");
  EXPECT_EQ(schoolSatResult.SchoolName, "");
  EXPECT_EQ(schoolSatResult.TestTakesNumber, 0);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean, 0);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 0);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 0);
}

TEST(SchoolSatResult, ModelInitializationWithParam) {
  const SchoolSatResult schoolSatResult(
      "01M292", "Henry Street School for International Studies ", 31, 391, 425,
      385);

  EXPECT_EQ(schoolSatResult.DBN, "01M292");
  EXPECT_EQ(schoolSatResult.SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResult.TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 425);
  EXPECT_EQ(schoolSatResult.WritingMean, 385);
}

TEST(Parser, CSVResultToString) {
  const SchoolSatResult schoolSatResult(
      "01M292", "Henry Street School for International Studies ", 31, 391, 425,
      385);

  const std::string expectedCsvString =
      "01M292,Henry Street School for International Studies ,31,391,425,385";

  const std::string csvString = Parser::ToString(schoolSatResult);

  EXPECT_EQ(csvString, expectedCsvString);
}

TEST(Parser, CSVEmptyResultToString) {
  SchoolSatResult schoolSatResult;

  schoolSatResult.DBN = "19K639";
  schoolSatResult.SchoolName = "Brooklyn Lab School ";

  const std::string expectedCsvString = "19K639,Brooklyn Lab School ,,,,";

  const std::string csvString = Parser::ToString(schoolSatResult);

  EXPECT_EQ(csvString, expectedCsvString);
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

  EXPECT_EQ(csvString, expectedCsvString);
}

TEST(Parser, CSVFullResultToSchoolSatResult) {
  const std::string csvString =
      "01M292,Henry Street School for International Studies ,31,391,425,385";

  const SchoolSatResult schoolSatResult = Parser::ToSchoolSatResult(csvString);

  EXPECT_EQ(schoolSatResult.DBN, "01M292");
  EXPECT_EQ(schoolSatResult.SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResult.TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 425);
  EXPECT_EQ(schoolSatResult.WritingMean, 385);
}

TEST(Parser, SchoolSatResultWithNameWithCommaToSchoolSatResult) {
  const std::string csvString = "14K478,\"Enterprise, Business and Technology "
                                "High School \",80,360,390,354";

  const SchoolSatResult schoolSatResult = Parser::ToSchoolSatResult(csvString);

  EXPECT_EQ(schoolSatResult.DBN, "14K478");
  EXPECT_EQ(schoolSatResult.SchoolName,
            "Enterprise, Business and Technology High School ");
  EXPECT_EQ(schoolSatResult.TestTakesNumber, 80);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean, 360);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 390);
  EXPECT_EQ(schoolSatResult.WritingMean, 354);
}

TEST(Parser, StringVectorToSchoolSatResultList) {
  std::vector<std::string> buffer = {
      "01M292,Henry Street School for International Studies ,31,391,425,385"};

  const std::unordered_map<std::string, SchoolSatResult> schoolSatResultList =
      Parser::ToSchoolSatList(buffer);

  ASSERT_FALSE(schoolSatResultList.empty());

  EXPECT_EQ(schoolSatResultList.at("01M292").DBN, "01M292");
  EXPECT_EQ(schoolSatResultList.at("01M292").SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResultList.at("01M292").TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResultList.at("01M292").CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResultList.at("01M292").MathematicsMean, 425);
  EXPECT_EQ(schoolSatResultList.at("01M292").WritingMean, 385);
}

TEST(Parser, CSVFileToSchoolSatResultList) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";
  std::vector<std::string> buffer = FileUtils::Read(inputfile);

  const std::unordered_map<std::string, SchoolSatResult> schoolSatResultList =
      Parser::ToSchoolSatList(buffer);

  ASSERT_FALSE(schoolSatResultList.empty());

  EXPECT_EQ(schoolSatResultList.at("01M292").DBN, "01M292");
  EXPECT_EQ(schoolSatResultList.at("01M292").SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResultList.at("01M292").TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResultList.at("01M292").CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResultList.at("01M292").MathematicsMean, 425);
  EXPECT_EQ(schoolSatResultList.at("01M292").WritingMean, 385);
}
