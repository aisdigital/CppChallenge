#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include <future>
#include <thread>

#include "CSVParser.h"

class CSVParserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a temporary CSV file with test data
        std::ofstream file("test.csv");
        file << "DBN,School Name,Test Takers,Critical Reading Mean,Maths Mean,Writing Mean\n";
	file << "01M292,Henry Street School for International Studies ,31,391,425,385\n";
        file.close();
    }

    void TearDown() override {
        std::remove("test.csv");
    }
};

TEST_F(CSVParserTest, parseTest) {
    CSVParser parser("test.csv");

    std::future<RecordsData> future = parser.parse();

    // Wait for parsing to complete
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    RecordsData recordsData = future.get();

    // Check the number of records
    EXPECT_EQ(recordsData.getRecordCount(), 1);

    // Check the values of the first record
    Record record = recordsData.getRecord("01M292");
    EXPECT_EQ(record.dbn, "01M292");
    EXPECT_EQ(record.schoolName, "Henry Street School for International Studies");
    EXPECT_EQ(record.testTakers, 31);
    EXPECT_EQ(record.criticalReadingMean, 391);
    EXPECT_EQ(record.mathsMean, 425);
    EXPECT_EQ(record.writingMean, 385);
}

