#include "gtest/gtest.h"

#include "../include/dataprocessor.h"
#include "../include/dataentry.h"
#include "../include/datareader.h"

#include <sstream>
#include <vector>
#include <map>

class DataProcessorTest : public ::testing::Test
{

protected:
    DataProcessorTest() {}
};

TEST_F(DataProcessorTest, ProcessRawEntries) {

    // Test Input
    std::vector<DataEntry> inputEntries;
    const std::vector<std::string> entriesAsString = {
        "00X121 Test123 10 5 4 6 ",
        "00X122 School123 11 5 4 6 ",
        "00X123 TestCool000 12 5 4 6 ",
        "00X123 TestFool001 12 5 4 6 ",
        "00X125/01X129 TestBool002 12 5 4 6 ",
        "00X124 MySchool 13 5 4 6 ",
        "00X124 OurSchool 13 5 4 6 ",
        "00X124 TheirSchool 13 5 4 6",
    };
    std::stringstream ss;
    for (const auto& str : entriesAsString) {
        ss << str;
    }
    while (!ss.eof()) {
        DataEntry entry;
        ss >> entry;
        entry.setAttribute(DataAttribute::SchoolName, entry.getSchoolName());
        inputEntries.push_back(entry);
    }

    // Test Output
    std::map<std::string, DataEntry> entries;

    //
    DataProcessor processor;
    entries = processor.processRawEntries(inputEntries);

    ASSERT_EQ(entries.size(), 7);
    ASSERT_TRUE(entries.find("00X125/01X129") != entries.end());
    ASSERT_TRUE(entries.find("01X129") != entries.end());
    ASSERT_TRUE(entries.find("01X125") == entries.end());
}


TEST_F(DataProcessorTest, SearchBySubString) {

    // Test Input
    std::map<std::string, DataEntry> inputEntries;
    const std::vector<std::string> entriesAsString = {
        "00X121 Test123 10 5 4 6 ",
        "00X122 School123 11 5 4 6 ",
        "00X123 TestCool000 12 5 4 6 ",
        "00X124 MySchool 13 5 4 6",
    };
    std::stringstream ss;
    for (const auto& str : entriesAsString) {
        ss << str;
    }
    while (!ss.eof()) {
        DataEntry entry;
        ss >> entry;
        entry.setAttribute(DataAttribute::SchoolName, entry.getSchoolName());
        inputEntries[entry.getDBN()] = entry;
    }

    // Test Output
    std::vector<DataEntry> entries;

    //
    DataProcessor processor;
    entries = processor.searchDataBySubString("oOl", inputEntries);
    ASSERT_EQ(entries.size(), 3);
    entries = processor.searchDataBySubString("EsT", inputEntries);
    ASSERT_EQ(entries.size(), 2);
    entries = processor.searchDataBySubString("00", inputEntries);
    ASSERT_EQ(entries.size(), 1);
    entries = processor.searchDataBySubString("123", inputEntries);
    ASSERT_EQ(entries.size(), 2);
    entries = processor.searchDataBySubString("My", inputEntries);
    ASSERT_EQ(entries.size(), 1);
    entries = processor.searchDataBySubString("Academy", inputEntries);
    ASSERT_EQ(entries.size(), 0);
}

TEST_F(DataProcessorTest, SearchByDBN) {

    // Test Input
    std::map<std::string, DataEntry> inputEntries;
    const std::vector<std::string> entriesAsString = {
        "00X121 Test123 10 5 4 6 ",
        "00X122 School123 11 5 4 6 ",
        "00X123 TestCool000 12 5 4 6 ",
        "00X124 MySchool 13 5 4 6",
    };
    std::stringstream ss;
    for (const auto& str : entriesAsString) {
        ss << str;
    }
    while (!ss.eof()) {
        DataEntry entry;
        ss >> entry;
        entry.setAttribute(DataAttribute::SchoolName, entry.getSchoolName());
        inputEntries[entry.getDBN()] = entry;
    }

    // Test Output
    std::string entryAsStr;

    //
    DataProcessor processor;
    auto searchedEntry = processor.searchDataByDBN("00X123", inputEntries);
    ASSERT_FALSE(searchedEntry.empty());
    if (!searchedEntry.empty()) {
        ASSERT_EQ(searchedEntry.back().getDBN(), "00X123");
    }
}

TEST_F(DataProcessorTest, ReadInputCSVandProcess) {

    // Test Input
    auto substring1 = "greeN";
    auto substring2 = "Bush";
    auto valueDBN = "08X530";

    // Test Output
    std::map<std::string, DataEntry> entries;
    std::vector<DataEntry> searchedEntries;

    //
    DataReader reader;
    DataProcessor processor;
    auto rawEntries = reader.readData();
    entries = processor.processRawEntries(rawEntries);
    ASSERT_EQ(entries.size(), 462);
    for (const auto& entry : entries) {
        ASSERT_GE(entry.second.getDBN().length(), 6);
    }

    searchedEntries = processor.searchDataBySubString(substring1, entries);
    ASSERT_EQ(searchedEntries.size(), 2);
    searchedEntries = processor.searchDataBySubString(substring2, entries);
    ASSERT_EQ(searchedEntries.size(), 4);
    auto searchedEntry = processor.searchDataByDBN(valueDBN, entries);
    ASSERT_FALSE(searchedEntry.empty());
    if (!searchedEntry.empty()) {
        ASSERT_EQ(searchedEntry.back().getDBN(), "08X530");
    }



}
