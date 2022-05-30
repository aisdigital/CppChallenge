#include "gtest/gtest.h"

#include "../include/datawriter.h"

#include "../include/dataentry.h"

class DataWriterTest : public ::testing::Test
{
    DataWriter m_dataWriter;

protected:
    DataWriterTest() {}

    bool createFolder(const std::string& folderpath)
    {
        return m_dataWriter.createFolder(folderpath);
    }
};

TEST_F(DataWriterTest, CreateFolder) {

    // Test Input
    std::string foldername = "__testoutput";

    // Test Output

    //
    createFolder(foldername);
}

TEST_F(DataWriterTest, CreateCSVFile) {

    // Test Input
    std::string foldername = "__testoutput";
    std::string filename = "__testoutput";
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

    //
    DataWriter writer;
    writer.createCSVFile(filename, inputEntries, foldername);
}
