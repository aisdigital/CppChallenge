/**
 * @file college_database_tests.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "college_database.h"

TEST(CollegeDatabaseTests, insert){
    CollegeDatabase database;
    College college1 = {"3", "School", "1", "2", "3", "4"};
    College college2 = {"2", "College", "", "", "", ""};
    College college3 = {"1", "Institute", "2", "", "10", "5"};

    database.insert(college1);
    database.insert(college2);
    database.insert(college3);

    std::string ret = database.select(CollegeDatabaseColumns::SchoolName, "").str();
    EXPECT_EQ("DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n2,College,,,,\n1,Institute,2,,10,5\n3,School,1,2,3,4\n", ret);
}

TEST(CollegeDatabaseTests, loadSuccess){
    CollegeDatabase database;
    CSVFile file("data_ok.csv");
    
    EXPECT_TRUE(database.load(file));
}

TEST(CollegeDatabaseTests, loadFail){
    CollegeDatabase database;
    CSVFile file("data_nok.csv");
    
    EXPECT_FALSE(database.load(file));
}

TEST(CollegeDatabaseTests, selectDBN){
    CollegeDatabase database;
    CSVFile file("data_ok.csv");
    
    ASSERT_TRUE(database.load(file));

    std::string ret = database.select(CollegeDatabaseColumns::DBN, "2").str();
    EXPECT_EQ("DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n2,College,,,,\n", ret);

    ret = database.select(CollegeDatabaseColumns::DBN, "5").str();
    EXPECT_EQ("DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n", ret);
}

TEST(CollegeDatabaseTests, selectSchoolName){
    CollegeDatabase database;
    CSVFile file("data_ok.csv");
    
    ASSERT_TRUE(database.load(file));

    std::string ret = database.select(CollegeDatabaseColumns::SchoolName, "ol").str();
    EXPECT_EQ("DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n2,College,,,,\n3,School,1,2,3,4\n", ret);

    ret = database.select(CollegeDatabaseColumns::SchoolName, "Escola").str();
    EXPECT_EQ("DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n", ret);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}