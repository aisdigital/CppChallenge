#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Exactly;
using ::testing::Return;

#include <iostream>
#include <fstream>

#include "college_data/data_storage.h"

using namespace std;
using namespace CollegeData;

// Fixture
class data_storage_test : public ::testing::Test, public ::testing::Environment
{
  protected:
	ifstream test_data;

	void SetUp() override
	{
		test_data.open(string(TEST_DATA_DIR) + "test_data.csv");
		if (!test_data.is_open())
		{
			GTEST_SKIP_("Test data file not found!");
		}
	}

	void TearDown() override
	{
		test_data.close();
	}
};

TEST_F(data_storage_test, constructor)
{
	ASSERT_NO_THROW(DataStorage(););
}

TEST_F(data_storage_test, AddDataFromCsv)
{
	CollegeData::DataStorage data_storage;
	ASSERT_NO_THROW(data_storage.AddDataFromCsv(test_data););
}

TEST_F(data_storage_test, GetNumberOfAddedSchools)
{
	CollegeData::DataStorage data_storage;
	data_storage.AddDataFromCsv(test_data);
	ASSERT_EQ(data_storage.GetNumberOfAddedSchools(), 458); // 460 - 2 duplicated DBN
}