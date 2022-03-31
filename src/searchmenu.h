#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "search.h"
#include "savecsvfile.h"

#define SEARCH_BY_NAME_MODE 1
#define SEARCH_BY_DBN_MODE 2
#define EXIT_PROGRAM 3

/**
 * @brief Class that responsible for manage search menu
 */
class SearchMenu {

public:
    /**
     * @brief Constructor
     */
    SearchMenu();

    /**
     * @brief Destructor
     */
    ~SearchMenu();

    /**
     * @brief Show menu on screen
     */
    void showMenu();

private:
    /**
     * @brief Manage the search mode accordingly user selection
     * 
     * @param searchMode
     */
    void manageSearch(int searchMode);

    /**
     * @brief Show save file message on screen
     * 
     * @param searchMode
     */
    void showSaveFileMessage();

    Search* m_search; /**< Search object*/
    SaveCsvFile* m_saveCsvFile; /**< SaveCsvFile object*/
    vector<string> m_result; /**< Search result*/
};

#endif // SEARCHMENU_H