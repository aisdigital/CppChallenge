/** \file search.h
 *  \brief Search class header
 */

#ifndef SEARCH_H_
#define SEARCH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Some important constants (they could also be defined as static const string).
// to-do: retrive the executable path name from main() to avoid trouble or use an absolute path; in the
// definitions below, it is assumed that the programm is executed from ../build/
#define INPUT_CSV_PATH  "./input/SAT__College_Board__2010_School_Level_Results.csv"
#define OUTPUT_CSV_PATH "./output/"

// Position of each data column in the input CSV file
// P.S.: In this first version, only the two below are used
#define POS_DBN  0
#define POS_NAME 1

using namespace std;

/**
 * \brief srchFlag typedef enum
 *
 *  Some useful constants.
 */
typedef enum
{
    SEARCH_BY_NAME = 0,
    SEARCH_BY_DBN,
    RES_FOUND,
    RES_NOT_FOUND,
    READ_CSV_OK,
    READ_CSV_FAIL,
    EXP_CSV_OK,
    EXP_CSV_FAIL,
    DONT_EXP_CSV
} srchFlag;

/**
 * \brief DataCSV typedef
 *
 *  Definition of the container of the whole data read from the CSV file.
 */
// to-do: create a class to properly handle the data read 
typedef vector< vector< string > > DataCSV;

// Search class definition
class Search
{
public:
    Search();

//    void searchMethod(srchFlag method, const string &keyword);

//    srchFlag exportResults(const DataCSV &data, const string &fileName);

    bool getStatus(void);

    void printResults(void);

private:
    bool status;

    void setStatus(bool newStatus);

    DataCSV data;

    DataCSV results;

    srchFlag readDataCSV(const string &fileName);

    srchFlag searchByName(const string &name);

//    srchFlag searchByDBN(const DataCSV &data, DataCSV &results, const string &dbn);
};

#endif /* SEARCH_H_ */