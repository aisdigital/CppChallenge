/**
 * @file college_database.h
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <algorithm>

#include "college.h"
#include "csv_file.h"
#include "college_database_columns.h"

#define COLLEGE_DATABASE_HEADER "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean"

class CollegeDatabase {
    public:

    CollegeDatabase() = default;
    bool load(CSVFile& file);
    void insert(const College& college);
    std::ostringstream select(const CollegeDatabaseColumns& column, const std::string& value);

    private:

    bool searchByDBN(College& college, const std::string& dbn);
    bool searchBySchoolName(std::vector<College>& colleges, const std::string& name);
    void loadCollege(const std::vector<std::string>& data);

    std::vector<College> m_database;
};

#endif