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

#include "college.h"

class CollegeDatabase {
    public:

    CollegeDatabase() = default;
    void load(const std::string& path);

    private:

    std::vector<College> m_database;
};

#endif