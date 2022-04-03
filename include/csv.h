/*
 * CSV.h
 *
 *  Created on: 02/04/2022
 *      Author: Gabriel Possamai
 */

#ifndef CSV_H_
#define CSV_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;
//! CSV class. 
/*!
    Create in memory CSV file that can be manipulated.
*/
class CSV {
    public:
        //! Constructor.
        /*!
            A constructor that receives the file path and a bool (true loads the file, false don't).
            \param filePath a string that contain the file path
            \param load a bool (true loads the file, false don't)
        */
        CSV(string filePath, bool load);
        //! Destructor.
        /*!
            A destructor.
        */
        virtual ~CSV();

        //! Save method.
        /*!
            Save the in memory CSV to a file.
        */
        void save();

        //! PrintCSV method.
        /*!
            Print the in memory CSV.
        */
        void PrintCSV();

        //! setFilePath method.
        /*!
            Set the file path.
            \param filePath a string that contain the file path
        */
        void setFilePath(string filePath);

        //! append method.
        /*!
            Append a single line to in memory CSV.
            \param line vector<string> CSV line
        */
        void append(vector<string> line);

        //! append method.
        /*!
            Append a multiple lines to in memory CSV.
            \param lines vector<vector<string>> a vector with CSV lines
        */
        void append(vector<vector<string>> lines);

        //! sort method.
        /*!
            Sort the in memory CSV by colum.
            \param col an int that indicates the colum
        */
        void sort(int col);

        //! find method.
        /*!
            Find multiple lines in memory CSV.
            \param col an int that indicates the column
            \param search a string containing what to search on
            \return Lines containing the search string
        */
        vector<vector<string>> find(int col, string search);

        //! findFirst method.
        /*!
            Find the first occurrence in memory CSV.
            \param col an int that indicates the column
            \param search a string containing what to search on
            \return the first occurrence line containing the search string
        */
        vector<string> findFirst(int col, string search);

        //! getHeader.
        /*!
            A constructor that receives the file path and a bool (true loads the file, false dont).
            \return the csv header.
        */
        vector<string> getHeader();

    private:
        //! filePath a private variable.
        /*!
            Stores the file path.
        */
        string filePath;

        //! content a private variable.
        /*!
            Stores the CSV file content.
        */
        vector<vector<string>> content;

        //! filePath a private variable.
        /*!
            Stores the max lenth found in the column and stores in the same column index.
        */
        vector<int> maxLen;

        //! setupMaxLen a private method.
        /*!
            Run the entire in memory CSV to populate maxLen variable.
        */
        void setupMaxLen();

        //! setupMaxLenHelper a private method.
        /*!
            Logic that update maxLen values if necessary.
            \param len an int vector of line content length by column
        */
        void setupMaxLenHelper(vector<int> len);
};

#endif /* CSV_H_ */
