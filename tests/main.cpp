#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include "doctest.h"
#include "main/csv_parser.hpp"
#include "main/level_results.hpp"

TEST_SUITE("Query by School Name")
{
    TEST_CASE("Empty table")
    {   
        std::stringstream strStream;
        CSVParser parser;
        parser.loadCSV(strStream);
        LevelResults levelResults;
        levelResults.processCSVTable(parser.getCSVTable());
        auto table = levelResults.queryBySchoolName("QUEENS");
        CHECK(table.size() == 0);
        

    }

    TEST_CASE("School name search")
    {
        std::stringstream strStream;
        strStream   << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

        CSVParser parser;
        parser.loadCSV(strStream);
        LevelResults levelResults;
        levelResults.processCSVTable(parser.getCSVTable());

        SUBCASE("Schools found")
        {
            auto table = levelResults.queryBySchoolName("QUEENS");
            CHECK(table.size() == 1);
            CHECK(table[0].size() == 6);
            CHECK(table[0][0] == "75Q256");
            CHECK(table[0][1] == "P256 QUEENS SCHOOL @ SAINT MARY'S ");
            CHECK(table[0][2] == "");
            CHECK(table[0][3] == "");
            CHECK(table[0][4] == "");
            CHECK(table[0][5] == "");

        }
    
        SUBCASE("Schools not found")
        {
            auto table = levelResults.queryBySchoolName("MANHATTAN");
            CHECK(table.size() == 0);
        }
    }

    TEST_CASE("School name search returns table in order")
    {
        std::stringstream strStream;
        strStream   << "28Q687,QUEENS HS FOR SCIENCE YORK COL ,99,613,650,612\n"
                    << "29Q248,QUEENS PREPARATORY ACADEMY ,46,372,388,381\n"
                    << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n"
                    << "25Q540,QUEENS ACADEMY ,22,400,395,391\n";

        CSVParser parser;
        parser.loadCSV(strStream);
        LevelResults levelResults;
        levelResults.processCSVTable(parser.getCSVTable());

        auto table = levelResults.queryBySchoolName("QUEENS");
        CHECK(table.size() == 4);
        CHECK(table[0][1] == "P256 QUEENS SCHOOL @ SAINT MARY'S ");
        CHECK(table[1][1] == "QUEENS ACADEMY ");
        CHECK(table[2][1] == "QUEENS HS FOR SCIENCE YORK COL ");
        CHECK(table[3][1] == "QUEENS PREPARATORY ACADEMY ");
    }
}

TEST_SUITE("Query by DBN")
{
    TEST_CASE("Empty table")
    {
        std::stringstream strStream;
        CSVParser parser;
        parser.loadCSV(strStream);
        LevelResults levelResults;
        levelResults.processCSVTable(parser.getCSVTable());
        auto table = levelResults.queryByDBN("29Q248");
        CHECK(table.size() == 0);

    }

    TEST_CASE("DBN search")
    {
        std::stringstream strStream;
        strStream   << "75Q256,P256 QUEENS SCHOOL @ SAINT MARY'S ,,,,\n";

        CSVParser parser;
        parser.loadCSV(strStream);
        LevelResults levelResults;
        levelResults.processCSVTable(parser.getCSVTable());

        SUBCASE("DBN found")
        {
            auto table = levelResults.queryByDBN("75Q256");
            CHECK(table.size() == 6);
            CHECK(table[0] == "75Q256");
            CHECK(table[1] == "P256 QUEENS SCHOOL @ SAINT MARY'S ");
            CHECK(table[2] == "");
            CHECK(table[3] == "");
            CHECK(table[4] == "");
            CHECK(table[5] == "");

        }
    
        SUBCASE("DBN not found")
        {
            auto table = levelResults.queryByDBN("222222");
            CHECK(table.size() == 0);
        }
    }
}