#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <gtest/gtest.h>
#include "main/csv_parser.hpp"
#include "main/level_results.hpp"

TEST(SchoolNameSearch, EmptyTable)
{
    std::stringstream strStream;
    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());
    auto table = levelResults.queryBySchoolName("QUEENS");
    EXPECT_EQ(table.size(), 0);
}

TEST(SchoolNameSearch, SchoolFound)
{
    std::stringstream strStream;
    strStream << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());

    auto table = levelResults.queryBySchoolName("QUEENS");
    EXPECT_EQ(table.size(), 1);
    EXPECT_EQ(table[0].size(), 6);
    EXPECT_STREQ(table[0][0].c_str(), "75Q256");
    EXPECT_STREQ(table[0][1].c_str(), "P256 QUEENS SCHOOL @ SAINT MARY'S ");
    EXPECT_STREQ(table[0][2].c_str(), "");
    EXPECT_STREQ(table[0][3].c_str(), "");
    EXPECT_STREQ(table[0][4].c_str(), "");
    EXPECT_STREQ(table[0][5].c_str(), "");
}

TEST(SchoolNameSearch, SchoolNotFound)
{

    std::stringstream strStream;
    strStream << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());

    auto table = levelResults.queryBySchoolName("MANHATTAN");
    EXPECT_EQ(table.size(), 0);
}

TEST(SchoolNameSearch, TableReturnsInOrder)
{

    std::stringstream strStream;
    strStream << "28Q687,QUEENS HS FOR SCIENCE YORK COL ,99,613,650,612\n"
              << "29Q248,QUEENS PREPARATORY ACADEMY ,46,372,388,381\n"
              << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n"
              << "25Q540,QUEENS ACADEMY ,22,400,395,391\n";

    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());

    auto table = levelResults.queryBySchoolName("QUEENS");
    EXPECT_EQ(table.size(), 4);
    EXPECT_STREQ(table[0][1].c_str(), "P256 QUEENS SCHOOL @ SAINT MARY'S ");
    EXPECT_STREQ(table[1][1].c_str(), "QUEENS ACADEMY ");
    EXPECT_STREQ(table[2][1].c_str(), "QUEENS HS FOR SCIENCE YORK COL ");
    EXPECT_STREQ(table[3][1].c_str(), "QUEENS PREPARATORY ACADEMY ");
}

TEST(DBNSearch, EmptyTable)
{

    std::stringstream strStream;
    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());
    auto table = levelResults.queryByDBN("29Q248");
    EXPECT_EQ(table.size(), 0);
}

TEST(DBNSearch, DNBFound)
{
    std::stringstream strStream;
    strStream << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());

    auto table = levelResults.queryByDBN("75Q256");
    EXPECT_EQ(table.size(), 6);
    EXPECT_STREQ(table[0].c_str(), "75Q256");
    EXPECT_STREQ(table[1].c_str(), "P256 QUEENS SCHOOL @ SAINT MARY'S ");
    EXPECT_STREQ(table[2].c_str(), "");
    EXPECT_STREQ(table[3].c_str(), "");
    EXPECT_STREQ(table[4].c_str(), "");
    EXPECT_STREQ(table[5].c_str(), "");
}

TEST(DBNSearch, DNBNotFound)
{
    std::stringstream strStream;
    strStream << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

    CSVParser parser;
    parser.loadCSV(strStream);
    LevelResults levelResults;
    levelResults.processCSVTable(parser.getCSVTable());
    auto table = levelResults.queryByDBN("222222");

    EXPECT_EQ(table.size(), 0);
}
