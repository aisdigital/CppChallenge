#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>

using std::string;
using std::list;
using std::map;
using std::vector;

class SATResultsManager
{
    private:
        map<string, string> m_SATResults;

        /**
         * @brief Split line into fields based on CSV representation.
         * 
         * @param line Input line.
         * 
         * @return Separated values.
         */
        vector<string> splitLine(string line);

        /**
         * @brief Check if a line is a CSV file header in the expected format.
         * 
         * @param line Input line.
         * 
         * @return true if it is a header.
         */
        bool isHeader(string line);

        /**
         * @brief Check if line contains the expected number of fields.
         * 
         * @param line Input line.
         * 
         * @return true if it's the expected format.
         */
        bool checkFields(string line);

        /**
         * @brief Extract DBN from a string representation of a SATResult.
         * 
         * @param line Input line.
         * 
         * @return DBN code, as a string.
         */
        string extractDBN(string line);

        /**
         * @brief Extract school name related to SAT result.
         * 
         * @param line Input line.
         * 
         * @return School Name.
         */
        string extractName(string line);

    public:
        /**
         * @brief Adds data to the manager.
         *  
         * @param data Data to be inserted. Each string is a CSV representation
         *             for a SATResult.
         * 
         * @return True if we could add all data.
         */
        bool addData(list<string> data);

        /**
         * @brief Finds SAT results by school name.
         * 
         * @param name Name to search.
         * 
         * @return Results with each line being a SAT result. In case no result
         *         is found, a single line with "No Results" will be returned.
         */
        list<string> findByName(string name);

        /**
         * @brief Finds a SAT result by DBN.
         * 
         * @param code DNB code.
         * 
         * @return SAT result for said code, or "Not found" if a result could 
         *         not be fetched.
         */
        string findByDBN(string code);
};