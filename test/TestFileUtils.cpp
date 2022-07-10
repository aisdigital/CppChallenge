#include "FileUtils.hpp"

#include <gtest/gtest.h>

TEST(FileUtils, ReadCSV) {

  const std::string inputfile = "input/SAT__College_Board__2010_School_Level_Results.csv";
  const std::string fileHeader = "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean";
  const std::vector<std::string> buffer = FileUtils::ReadCSV(inputfile);

  EXPECT_STREQ(buffer[0].c_str(), fileHeader.c_str());
}