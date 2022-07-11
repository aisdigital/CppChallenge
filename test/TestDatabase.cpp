#include <gtest/gtest.h>

#include "Database.hpp"
#include "FileUtils.hpp"

TEST(FileUtils, Read) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";
  const std::string fileHeader =
      "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics "
      "Mean,Writing Mean";
  const std::string csvString =
      "01M292,Henry Street School for International Studies ,31,391,425,385";

  const std::vector<std::string> buffer = FileUtils::Read(inputfile);

  ASSERT_FALSE(buffer.empty());

  EXPECT_STREQ(buffer[0].c_str(), fileHeader.c_str());
  EXPECT_STREQ(buffer[1].c_str(), csvString.c_str());
}

TEST(Database, FindByDBN) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  Database database;
  database.Read(inputfile);

  auto schoolSatResult = database.FindByDBN("01M292");

  EXPECT_EQ(schoolSatResult.DBN, "01M292");
  EXPECT_EQ(schoolSatResult.SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResult.TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResult.CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResult.MathematicsMean, 425);
  EXPECT_EQ(schoolSatResult.WritingMean, 385);
}

TEST(Database, ExactSearchFindBySchoolName) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  Database database;
  database.Read(inputfile);

  auto schoolSatResultList = database.FindBySchoolName(
      "Henry Street School for International Studies ");

  ASSERT_FALSE(schoolSatResultList.empty());

  EXPECT_EQ(schoolSatResultList[0].DBN, "01M292");
  EXPECT_EQ(schoolSatResultList[0].SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResultList[0].TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResultList[0].CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResultList[0].MathematicsMean, 425);
  EXPECT_EQ(schoolSatResultList[0].WritingMean, 385);
}

TEST(Database, SimilarTermSearchFindBySchoolName) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  Database database;
  database.Read(inputfile);

  auto schoolSatResultList = database.FindBySchoolName("Henry Street");

  ASSERT_FALSE(schoolSatResultList.empty());

  EXPECT_EQ(schoolSatResultList[0].DBN, "01M292");
  EXPECT_EQ(schoolSatResultList[0].SchoolName,
            "Henry Street School for International Studies ");
  EXPECT_EQ(schoolSatResultList[0].TestTakesNumber, 31);
  EXPECT_EQ(schoolSatResultList[0].CriticalReadingMean, 391);
  EXPECT_EQ(schoolSatResultList[0].MathematicsMean, 425);
  EXPECT_EQ(schoolSatResultList[0].WritingMean, 385);
}

TEST(Database, UnableToFindBySchoolName) {
  const std::string inputfile =
      "input/SAT__College_Board__2010_School_Level_Results.csv";

  Database database;
  database.Read(inputfile);

  auto schoolSatResultList = database.FindBySchoolName("ZZZZZZZZZZZ");

  EXPECT_TRUE(schoolSatResultList.empty());
}
