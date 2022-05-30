

#include "gtest/gtest.h"

#include "../include/nameprocessor.h"

#include <algorithm>
#include <iostream>
#include <random>

class NameProcessorTest : public ::testing::Test
{
protected:
    NameProcessorTest() {}
public:
    std::string generateRandomString(unsigned size)
    {
        static const std::string ALLOWED_CHARS = 
        "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0, ALLOWED_CHARS.size() - 1);

        std::string newString;
        for (unsigned i = 0; i < size; i++) {
            auto randomLetter = ALLOWED_CHARS[distribution(generator)];
            newString += randomLetter;
        }
        return newString;
    }
};

TEST_F(NameProcessorTest, CapitalizeTest_Input) {

    // Test Input
    std::string schoolName = "Bronx Latin School";
    // Test Output
    std::string newName;

    //
    NameProcessor processor;
    newName = processor.processShoolName(schoolName);
    ASSERT_TRUE(std::all_of(newName.begin(), newName.end(),
    [](unsigned char c)
    {
        return (c == std::toupper(c));
    }));
}

TEST_F(NameProcessorTest, CapitalizeTest_Random) {

    // Test Input
    const std::string schoolName = NameProcessorTest::generateRandomString(12);
    // Test Output
    std::string newName;

    //
    NameProcessor processor;
    newName = processor.processShoolName(schoolName);
    ASSERT_TRUE(std::all_of(newName.begin(), newName.end(),
    [](unsigned char c)
    {
        return (c == std::toupper(c));
    }));
}

TEST_F(NameProcessorTest, ExpandAcronymsTest_Input) {

    // Test Input
    const std::vector<std::string> schoolNames = 
    {
     "Bronx Latin School",
     "NYC iSchool",
     "BROOKLYN HS MUSIC AND THEATER",
     "P256 QUEENS SCHOOL @ SAINT MARY'S COMM C",
     "BRONX ENGINEERING & TECH ACADEMY"
    };
    // Test Output
    std::vector<std::string> newNames;

    //
    NameProcessor processor;
    for (const auto& name : schoolNames) {
        auto newName = processor.processShoolName(name);
        processor.expandAcronyms(newName);
        newNames.push_back(newName);   
    }
    for (const auto& newName : newNames) {
        bool has_acronym = false;
        unsigned posStart = 0;
        while (true) {
            auto posFound = newName.find(" ", posStart);
            if (posFound == std::string::npos) {
                break;
            } else {
                auto word = newName.substr(posStart, posFound - posStart);
                for (const auto& acronym : NameProcessor::ACRONYM_LIST) {
                    if (!acronym.first.compare(word)) {
                        has_acronym = true;
                        break;
                    }
                }
                posStart += word.length() + 1;
            }
        }
        ASSERT_FALSE(has_acronym);
    }
}

TEST_F(NameProcessorTest, RemoveSymbolsTest_Input) {

    // Test Input
    const std::vector<std::string> schoolNames =
    {
     "Bronx Latin School",
     "\"New Explorations into Sci, Tech and Math HS \"",
     "P256 QUEENS SCHOOL @ SAINT MARY'S COMM C"
    };
    // Test Output
    std::vector<std::string> newNames;

    //
    NameProcessor processor;
    for (const auto& name : schoolNames) {
        auto newName = processor.processShoolName(name);
        newNames.push_back(newName);
    }
}

TEST_F(NameProcessorTest, ContainsSubstring_Input) {

    // Test Input
    const std::vector<std::string> schoolNames =
    {
     "Bronx Latin School",
     "\"New Explorations into Sci, Tech and Math HS \"",
     "P256 QUEENS SCHOOL @ SAINT MARY'S COMM C",
     "BRONX ENGINEERING & TECH ACADEMY",
     "GREEN SCHOOL: AN ACADEMY FOR ENVIRONMEN"
    };

    // Test Output
    std::vector<std::string> newNames;
    std::string testSubString;

    //
    NameProcessor processor;
    for (const auto& name : schoolNames) {
        auto newName = processor.processShoolName(name);
        newNames.push_back(newName);
    }

    testSubString = "bron";
    ASSERT_TRUE(processor.hasSubString(newNames[0], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[1], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[2], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[3], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[4], testSubString));

    testSubString = "hool";
    ASSERT_TRUE(processor.hasSubString(newNames[0], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[1], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[2], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[3], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[4], testSubString));

    testSubString = "n sch";
    ASSERT_TRUE(processor.hasSubString(newNames[0], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[1], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[2], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[3], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[0], testSubString));

    testSubString = "ee";
    ASSERT_FALSE(processor.hasSubString(newNames[0], testSubString));
    ASSERT_FALSE(processor.hasSubString(newNames[1], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[2], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[3], testSubString));
    ASSERT_TRUE(processor.hasSubString(newNames[4], testSubString));
}
