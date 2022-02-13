/** \file search_ui.h
 *  \brief Contain definitions for useful user interface functions.
 */

#ifndef SEARCH_UI_H_
#define SEARCH_UI_H_

#include <string>

using namespace std;

// The definitions used here could also be contained in a class definition written in search.hpp

/**
 * \brief uiFlag typedef enum
 *
 *  Some useful constants.
 */
typedef enum
{
    NO_EXP = 0,
} uiFlag;

void printMainMenu(int &option);

void printMainMenuSearchByName(string &keyword);

uiFlag printExpMenuSearchByName(string &fileName);

void printMenuSearchByDBN(string &dbn);

#endif /* SEARCH_UI_H_ */