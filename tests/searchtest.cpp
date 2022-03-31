#include "searchtest.h"

SearchTest::~SearchTest()
{

}

void SearchTest::SetUp()
{
    m_search = new Search();

    m_csvFile = CsvFile::getInstance();
    
    m_input.push_back("02M298,PACE HIGH SCHOOL ,71,424,448,423");
    m_input.push_back("02M300,Urban Assembly School of Design and Construction ,49,405,446,415");
    m_input.push_back("02M303,The Facing History School ,59,381,373,377");
    m_input.push_back("02M305,Urban Assembly Academy of Government and Law ,48,411,406,411");
    m_input.push_back("02M308,LOWER MANHATTAN ARTS ACADEMY ,35,409,381,412");

    m_csvFile->setCsvFile(m_input);
}

void SearchTest::TearDown()
{
    delete m_search;
    m_input.clear();
}

TEST_F(SearchTest, searchNameTest)
{
    string filter = "PACE HIGH SCHOOL";
    vector<string> result = m_search->searchName(filter);
    EXPECT_EQ(result[0], "02M298,PACE HIGH SCHOOL ,71,424,448,423");
}

TEST_F(SearchTest, searchNameSizeResultTest)
{
    string filter = "Urban Assembly";
    vector<string> result = m_search->searchName(filter);
    EXPECT_EQ(result.size(), 2);
}

TEST_F(SearchTest, searchNameEmptyTest)
{
    string filter = "High";
    vector<string> result = m_search->searchName(filter);
    EXPECT_EQ(result.size(), 0);
}

TEST_F(SearchTest, searchNameOrderedTest)
{
    string filter = "Urban Assembly";
    vector<string> result = m_search->searchName(filter);
    ASSERT_EQ(result[0], "02M305,Urban Assembly Academy of Government and Law ,48,411,406,411");
    ASSERT_EQ(result[1], "02M300,Urban Assembly School of Design and Construction ,49,405,446,415");
}

TEST_F(SearchTest, searchDbnTest)
{
    string filter = "02M303";
    vector<string> result = m_search->searchName(filter);
    EXPECT_EQ(result[0], "02M303,The Facing History School ,59,381,373,377");
}

TEST_F(SearchTest, searchDbnEmptyTest)
{
    string filter = "02M309";
    vector<string> result = m_search->searchName(filter);
    EXPECT_EQ(result.size(), 0);
}