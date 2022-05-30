#include "gtest/gtest.h"

#include "../include/dataentry.h"

#include <iostream>
#include <string>

class DataEntryTest : public ::testing::Test
{
protected:
    DataEntryTest() {}
public:

};

TEST_F(DataEntryTest, ConvertAttributeToStringTest) {

    // Test Input
    static const std::vector<DataAttribute> attributes =
    {
        DataAttribute::DBNValue,
        DataAttribute::SchoolName,
        DataAttribute::TestTakers,
        DataAttribute::ReadingMean,
        DataAttribute::MathMean,
        DataAttribute::WritingMean,
        DataAttribute::NotFound
    };
    // Test Output
    static const std::vector<std::string> attributesAsStr =
    {
        "DBN",
        "School Name",
        "Number of Test Takers",
        "Critical Reading Mean",
        "Mathematics Mean",
        "Writing Mean",
        ""
    };

    //
    for (size_t i = 0; i < attributes.size(); i++) {
        ASSERT_EQ(convertDataAttributeToString(attributes[i]), attributesAsStr[i]);
    }
}

TEST_F(DataEntryTest, ConvertStringToAttributesTest) {

    // Test Input
    static const std::vector<std::string> attributesAsStr =
    {
        "DBN",
        "School Name",
        "Number of Test Takers",
        "Critical Reading Mean",
        "Mathematics Mean",
        "Writing Mean",
        ""
    };

    // Test Output
    static const std::vector<DataAttribute> attributes =
    {
        DataAttribute::DBNValue,
        DataAttribute::SchoolName,
        DataAttribute::TestTakers,
        DataAttribute::ReadingMean,
        DataAttribute::MathMean,
        DataAttribute::WritingMean,
        DataAttribute::NotFound
    };

    //
    for (size_t i = 0; i < attributes.size(); i++) {
        ASSERT_EQ(convertStrToDataAttribute(attributesAsStr[i]), attributes[i]);
    }
}
