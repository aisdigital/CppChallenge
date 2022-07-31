/**
 * @file console.h
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <sstream>

#ifndef CONSOLE_H
#define CONSOLE_H

#include "operation.h"

class Console {
    public:

    static void printOperationsMenu();
    static Operation getUserOperation();
    static std::string getUserSearch();
    static bool getUserFilePreference();
    static void printSearchResult(const std::ostringstream& stream);
};

#endif