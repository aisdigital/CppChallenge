#include <gtest/gtest.h>
#include "../include/output.hpp"
#include "../include/query.hpp"
#include "../include/storage.hpp"

//! read CSV file
std::ifstream file("./input/SAT__College_Board__2010_School_Level_Results.csv");
std::istream &fileDescriptor = file;
//! store data from CSV file in memory
std::vector<std::vector<std::string>> data = readCSV(fileDescriptor);

TEST(searchBySchoolName, keyExclamationMark)
{
    std::vector<Entry> entriesSchoolName = {};
    std::string key = "!";
    searchBySchoolName(data, key, entriesSchoolName);
    EXPECT_EQ(entriesSchoolName.size(), 0);
}

TEST(searchBySchoolName, keyAt)
{
    std::vector<Entry> entriesSchoolName = {};
    std::string key = "@";
    searchBySchoolName(data, key, entriesSchoolName);
    EXPECT_EQ(entriesSchoolName.size(), 4);
}

TEST(searchBySchoolName, keyNEW)
{
    std::vector<Entry> entriesSchoolName = {};
    std::string key = "NEW";
    searchBySchoolName(data, key, entriesSchoolName);
    EXPECT_EQ(entriesSchoolName.size(), 11);
}

TEST(searchBySchoolName, alphabeticSorting)
{
    std::vector<Entry> entriesSchoolName = {};
    std::string key = "NEW";
    searchBySchoolName(data, key, entriesSchoolName);
    EXPECT_EQ(entriesSchoolName[0].getSchoolName(), "EAST NEW YORK FAMILY ACADEMY ");
}

TEST(searchByDBN, key000000)
{
    Entry entryDBN = {};
    std::string key = "000000";
    searchByDBN(data, key, entryDBN);
    EXPECT_EQ(entryDBN.empty(), true);
}

TEST(searchByDBN, key01M450)
{
    Entry entryDBN = {};
    std::string key = "01M450";
    searchByDBN(data, key, entryDBN);
    EXPECT_EQ(entryDBN.getSchoolName(), "East Side Community High School ");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    // TODO tests
    return RUN_ALL_TESTS();
}