#include <fstream>
#include "gtest/gtest.h"

#include "Database.hpp"
#include "DatabaseRecord.hpp"
#include "tools/cpp/runfiles/runfiles.h"

using bazel::tools::cpp::runfiles::Runfiles;

TEST(DatabaseTest, testSearchByDbnSuccess)
{
    Database db("test/testFile.csv");
    bool found;
    DatabaseRecord record = db.searchByDbn("1a2B3c", found);

    std::string actual_dbn = record.getDbn();

    EXPECT_EQ(found, true) << "This value must be true";
    EXPECT_EQ(record.getDbn(), "1A2B3C") << "This value must be 1A2B3C";
    EXPECT_EQ(record.getSchoolName(), "Test School 1") << "This value must be 'Test School 1'";
    EXPECT_EQ(record.getTestTakers(), "200") << "This value must be 200";
    EXPECT_EQ(record.getCriticalReadingMean(), "50") << "This value must be 50";
    EXPECT_EQ(record.getMathMean(), "60") << "This value must be 60";
    EXPECT_EQ(record.getWritingMean(), "70") << "This value must be 70";
}

TEST(DatabaseTest, testSearchByDbnSuccessQuoted)
{
    Database db("test/testFile.csv");
    bool found;
    DatabaseRecord record = db.searchByDbn("6d7E9f", found);

    std::string actual_dbn = record.getDbn();

    EXPECT_EQ(found, true) << "This value must be true";
    EXPECT_EQ(record.getDbn(), "6D7E9F") << "This value must be 6D7E9F";
    EXPECT_EQ(record.getSchoolName(), "Test, School, 2") << "This value must be 'Test, School, 2'";
    EXPECT_EQ(record.getTestTakers(), "450") << "This value must be 450";
    EXPECT_EQ(record.getCriticalReadingMean(), "10") << "This value must be 10";
    EXPECT_EQ(record.getMathMean(), "20") << "This value must be 20";
    EXPECT_EQ(record.getWritingMean(), "30") << "This value must be 30";
}

TEST(DatabaseTest, testSearchByDbnFail)
{
    Database db("test/testFile.csv");
    bool found;
    DatabaseRecord record = db.searchByDbn("6d7E0f", found);

    std::string actual_dbn = record.getDbn();

    EXPECT_EQ(found, false) << "This value must be false";
}

TEST(DatabaseTest, testSearchByNameSuccess)
{
    Database db("test/testFile.csv");
    bool found;
    std::vector<DatabaseRecord> records = db.searchByName("school", found);

    EXPECT_EQ(found, true) << "This value must be true";
    EXPECT_EQ(records.size(), 2) << "This value must be 2";
    
    DatabaseRecord rec1("1A2B3C","Test School 1", "200", "50", "60", "70");
    DatabaseRecord rec2("6D7E9F","Test, School, 2", "450", "10", "20", "30");

    EXPECT_EQ(records[0].getDbn(), rec1.getDbn()) << "Record 1 DBN is incorrect";
    EXPECT_EQ(records[0].getSchoolName(), rec1.getSchoolName()) << "Record 1 schoolName is incorrect";
    EXPECT_EQ(records[0].getTestTakers(), rec1.getTestTakers()) << "Record 1 testTakers is incorrect";
    EXPECT_EQ(records[0].getCriticalReadingMean(), rec1.getCriticalReadingMean()) << "Record 1 criticalReading is incorrect";
    EXPECT_EQ(records[0].getMathMean(), rec1.getMathMean()) << "Record 1 math is incorrect";
    EXPECT_EQ(records[0].getWritingMean(), rec1.getWritingMean()) << "Record 1 writing is incorrect";

    EXPECT_EQ(records[1].getDbn(), rec2.getDbn()) << "Record 2 DBN is incorrect";
    EXPECT_EQ(records[1].getSchoolName(), rec2.getSchoolName()) << "Record 2 schoolName is incorrect";
    EXPECT_EQ(records[1].getTestTakers(), rec2.getTestTakers()) << "Record 2 testTakers is incorrect";
    EXPECT_EQ(records[1].getCriticalReadingMean(), rec2.getCriticalReadingMean()) << "Record 2 criticalReading is incorrect";
    EXPECT_EQ(records[1].getMathMean(), rec2.getMathMean()) << "Record 2 math is incorrect";
    EXPECT_EQ(records[1].getWritingMean(), rec2.getWritingMean()) << "Record 2 writing is incorrect";
}

TEST(DatabaseTest, testSearchByNameFail)
{
    Database db("test/testFile.csv");
    bool found;
    std::vector<DatabaseRecord> records = db.searchByName("wrong_name", found);

    EXPECT_EQ(found, false) << "This value must be false";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}