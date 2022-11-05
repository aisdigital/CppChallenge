#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Exactly;
using ::testing::Return;

#include <iostream>
#include <fstream>

#include "college_data/data_storage.h"
#include "college_data/data_analysis.h"

using namespace std;
using namespace CollegeData;

// Fixture
class data_analysis_test : public ::testing::Test
{
  protected:
	ifstream test_data;
	DataStorage data_storage;

	void SetUp() override
	{
		test_data.open(string(TEST_DATA_DIR) + "test_data.csv");
		if (!test_data.is_open())
		{
			GTEST_SKIP_("Test data file not found!");
		}
		data_storage.AddDataFromCsv(test_data);
	}

	void TearDown() override
	{
		test_data.close();
	}
};

TEST_F(data_analysis_test, constructor)
{
	ASSERT_NO_THROW(DataAnalysis(););
}

TEST_F(data_analysis_test, SearchByDbn)
{
	DataAnalysis data_analysis;
	EXPECT_EQ(data_analysis.SearchByDbn("!@#$%^", data_storage), 0);
	EXPECT_EQ(data_analysis.SearchByDbn("30Q301", data_storage), 1);
}

TEST_F(data_analysis_test, SearchByName)
{
	DataAnalysis data_analysis;
	EXPECT_GT(data_analysis.SearchByName("High", data_storage), 256);// 256 school names have the "high" word
}

TEST_F(data_analysis_test, GetLastResult)
{
	DataAnalysis data_analysis;
	data_analysis.SearchByName("monroe", data_storage);

	string s_aux =// Manually extracted from /data/test_data.csv -> Name alphabetic order
		"12X692,MONROE ACAD VISUAL ARTS DESGN ,70,346,341,356\n"
		"12X690,MONROE CAMPUS ,47,355,369,366\n"
		"12X428,YABC at Monroe Academy ,11,386,345,388\n";

	EXPECT_EQ(data_analysis.GetLastResult().str(), s_aux);
}