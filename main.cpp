// Challenge C++ AISDigital

#include <iostream>

#include "search.h"
#include "search_ui.h"

int main(int argc, const char * argv[]) { 
    Search *search = new Search();
    int userOpt = 0;
    string keyword, fileName;
    
    //Check if everything is fine
    if(!search->getStatus()) {
      std::cerr << "Fatal error." << std::endl;
    }
    else {
      std::cout << "Everything is fine." << std::endl << std::endl;
    }

/*
    // Test search method
    if(search->searchMethod(SEARCH_BY_NAME, "SMITH") == RES_NOT_FOUND) {
        std::cout << "No results found." << std::endl;
    }
    else if(search->exportResults("./output/newfile.csv") == EXP_CSV_FAIL) {
        std::cout << "Fail to export results." << std::endl;
    }
    search->printResults();
*/
// Test user interface
    //printMainMenu(userOpt);

    // Search by name menu
    //printMainMenuSearchByName(keyword);

/*    // Search by name -> export file menu
    if(printExpMenuSearchByName(fileName) == DO_EXP) {
        cout << "Export results: " << endl;
    }
    else {
        cout << "No export." << endl;
    }

    // Search by DBN menu
    printMenuSearchByDBN(keyword);

    cout << "User input = " << keyword << endl;
*/
    delete search;

    return 0;
}

