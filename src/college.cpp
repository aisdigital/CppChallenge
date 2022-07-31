/**
 * @file college.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "college.h"

bool College::operator<(const College& college){
    return dbn < college.dbn;
}

std::ostream& operator<<(std::ostream& os, const College& college){
    os << college.dbn << "," << college.name << "," << college.test_takers << "," << 
        college.reading_mean << "," << college.math_mean << "," << college.writing_mean; 
}