#ifndef SEARCHTEST_H
#define SEARCHTEST_H

#include "search.h"
#include "csvfile.h"

#include <gtest/gtest.h>

using namespace ::testing;

/**
 * @brief Test the Search class
 * 
 */
class SearchTest : public Test {

protected:
    /**
     * @brief Virtual destructor
     * 
     */
    virtual ~SearchTest();
    
    /**
     * @brief Set up method responsible for creating the search and csv file objects with a predefined set of parameters
     *
     */
    virtual void SetUp();

    /**
     * @brief Default tear down method
     *
     */
    virtual void TearDown();

    Search* m_search; /**< Search object*/
    vector<string> m_input; /**< Vector of strings to simulate csv file data*/
    CsvFile* m_csvFile; /**< CsvFile object*/
};

#endif // SEARCHTEST_H