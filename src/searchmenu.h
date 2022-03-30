#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "search.h"
#include "savecsvfile.h"

#define SEARCH_BY_NAME_MODE 1
#define SEARCH_BY_DBN_MODE 2
#define EXIT_PROGRAM 3

class SearchMenu {

public:
    SearchMenu();

    ~SearchMenu();

    void showMenu();

private:

    void manageSearch(int searchMode);

    void showSaveFileMessage();

    Search* m_search;
    SaveCsvFile* m_saveCsvFile;
    vector<string> m_result;
};

#endif // SEARCHMENU_H