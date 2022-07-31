/**
 * @file college.h
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef COLLEGE_H
#define COLLEGE_H

#include <string>
#include <sstream>

class College {
    public:

    std::string dbn;
    std::string name;
    std::string test_takers;
    std::string reading_mean;
    std::string math_mean;
    std::string writing_mean;

    bool operator<(const College& college);
    friend std::ostream& operator<<(std::ostream& os, const College& college);
};

#endif