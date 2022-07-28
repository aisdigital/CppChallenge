/**
 * @file college.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "college.h"

bool College::operator<(const College& college){
    return name < college.name;
}