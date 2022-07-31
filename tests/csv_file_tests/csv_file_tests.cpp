/**
 * @file csv_file_tests.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "csv_file.h"

TEST(CSVFileTests, open){
    CSVFile file;
    file.open("data.csv");
    auto data = file.data();

    ASSERT_EQ(file.cols(), 3);
    ASSERT_EQ(file.rows(), 4);

    ASSERT_EQ(data[0].size(), 3);
    ASSERT_EQ("column0", data[0][0]);
    ASSERT_EQ("column1", data[0][1]);
    ASSERT_EQ("column2", data[0][2]);

    ASSERT_EQ(data[1].size(), 3);
    ASSERT_EQ("\"a,b,c\"", data[1][0]);
    ASSERT_EQ("", data[1][1]);
    ASSERT_EQ("abc", data[1][2]);

    ASSERT_EQ(data[2].size(), 3);
    ASSERT_EQ("abc", data[2][0]);
    ASSERT_EQ("\"a,b,c\"", data[2][1]);
    ASSERT_EQ("", data[2][2]);

    ASSERT_EQ(data[3].size(), 3);
    ASSERT_EQ("abc", data[3][0]);
    ASSERT_EQ("abc", data[3][1]);
    ASSERT_EQ("\"a,b,c\"", data[3][2]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}