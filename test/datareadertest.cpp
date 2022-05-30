#include "gtest/gtest.h"

#include "../include/datareader.h"
#include "../include/dataentry.h"

#include <random>
#include <vector>

class DataReaderTest : public ::testing::Test
{
    DataReader m_reader;

protected:
    DataReaderTest() {}

    std::vector<std::string> readAttributeOrder(const std::string& firstLine)
    {
        m_reader = DataReader();
        m_reader.readAttributeOrder(firstLine);
        return m_reader.m_attributesOrder;
    }

    DataEntry convertLineToAtributesOrder(const std::string& line)
    {
        m_reader = DataReader();
        static const std::vector<std::string> attributesOrder =
        {
                "DBN",
                "School Name",
                "Number of Test Takers",
                "Critical Reading Mean",
                "Mathematics Mean",
                "Writing Mean"
        };
        m_reader.m_attributesOrder = attributesOrder;
        return m_reader.convertLineToEntry(line);
    }

    void convertLinesToEntries(const std::vector<std::string>& lines,
                               std::vector<DataEntry>& entries)
    {
        m_reader = DataReader();
        static const std::vector<std::string> attributesOrder =
        {
                "DBN",
                "School Name",
                "Number of Test Takers",
                "Critical Reading Mean",
                "Mathematics Mean",
                "Writing Mean"
        };
        m_reader.m_attributesOrder = attributesOrder;
        m_reader.convertLinesToEntries(lines, entries);
    }

public:
    std::string generateRandomName(unsigned size) const
    {
        static const std::string ALLOWED_CHARS =
        "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz \'\"@!?";

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

    std::string generateDBN() const
    {
        static const std::string ALLOWED_CHARS =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static const std::string ALLOWED_NUMS =
        "0123456789";

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distributionChars(0, ALLOWED_CHARS.size() - 1);
        std::uniform_int_distribution<> distributionNums(0, ALLOWED_NUMS.size() - 1);

        std::string newDBN;
        newDBN.push_back(ALLOWED_NUMS[distributionNums(generator)]);
        newDBN.push_back(ALLOWED_NUMS[distributionNums(generator)]);
        newDBN.push_back(ALLOWED_CHARS[distributionChars(generator)]);
        newDBN.push_back(ALLOWED_NUMS[distributionNums(generator)]);
        newDBN.push_back(ALLOWED_NUMS[distributionNums(generator)]);
        newDBN.push_back(ALLOWED_NUMS[distributionNums(generator)]);

        return newDBN;
    }

    std::string generateTestTakers() const
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0, 1200);

        return std::to_string(distribution(generator));
    }

    std::string generateMean() const
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::normal_distribution<> distribution(500.0, 200.0);

        float mean = distribution(generator);


        return std::to_string(
                    static_cast<unsigned>(
                        std::max(0.0, std::min(999.0, static_cast<double>(mean)))));
    }

    std::string generateRandomLine() const
    {
        std::string randomLine;
        randomLine += generateDBN() + ",";
        randomLine += generateRandomName(12) + ",";
        randomLine += generateTestTakers() + ",";
        randomLine += generateMean() + ",";
        randomLine += generateMean() + ",";
        randomLine += generateMean();

        return randomLine;
    }
};

TEST_F(DataReaderTest, ReadAttributesOrder) {

    // Test Input
    static const std::string attributesAsStr =
            "DBN,"
            "School Name,"
            "Number of Test Takers,"
            "Critical Reading Mean,"
            "Mathematics Mean,"
            "Writing Mean";


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
    std::vector<std::string> attributesOrder = readAttributeOrder(attributesAsStr);
    for (size_t i = 0; i < attributesOrder.size(); i++) {
        ASSERT_EQ(convertDataAttributeToString(attributes[i]),
                  attributesOrder[i]);
    }
}

TEST_F(DataReaderTest, ConvertLineToEntryTest_Random) {

    // Test Input
    std::string randomLine = generateRandomLine();

    // Test Output
    DataEntry entry;

    //
    entry = convertLineToAtributesOrder(randomLine);
    ASSERT_TRUE(entry.getDBN().length() == 6);
    ASSERT_TRUE(entry.getSchoolName().length() > 1);
}

TEST_F(DataReaderTest, ConvertLinesToEntriesTest_Random) {

    // Test Input
    size_t nLines = 13;
    std::vector<std::string> randomLines;
    for (size_t i = 0; i < nLines; i++) {
        randomLines.push_back(generateRandomLine());
    }

    // Test Output
    std::vector<DataEntry> entries;

    //
    convertLinesToEntries(randomLines, entries);
    for (const auto& entry : entries) {
        ASSERT_TRUE(entry.getDBN().length() == 6);
        ASSERT_TRUE(entry.getSchoolName().length() > 1);
    }
}

TEST_F(DataReaderTest, ReadInputCSV) {

    // Test Input

    // Test Output
    std::vector<DataEntry> entries;

    //
    DataReader reader;
    entries = reader.readData();
    ASSERT_EQ(entries.size(), 460);
    for (const auto& entry : entries) {
        ASSERT_GE(entry.getDBN().length(), 6);
    }
}
