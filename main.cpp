// Challenge C++ AISDigital

#include <iostream>

#include "search.h"
#include "search_ui.h"

int main(int argc, const char * argv[]) { 
    Search *search = new Search();
    int userOpt = 0;
    string keyword, fileName;
    //tmp
    bool exit = false; 
    
    //Check if everything is fine
    if(!search->getStatus()) {
      std::cerr << "Fatal error." << std::endl;
    }

    // to-do: implement the program logic more elegantly using a state machine or a class
    while(!exit) {
        // Print main menu and get the user's chosen option
        printMainMenu(userOpt);

        switch(userOpt) {
            case MAIN_OPT1:
                // Clear the results container first
                search->clearResults();
                // Print the 'search by name' menu and get the user's keyword 
                printMainMenuSearchByName(keyword);
                // Apply 'search by name' method
                if(search->searchMethod(SEARCH_BY_NAME, keyword) == RES_NOT_FOUND) {
                    std::cout << "No results were found!" << std::endl << std::endl;
                }
                else {
                    // Print the results on the screen
                    search->printResults();
                    // Print the 'search by name -> export file' menu and get user's fileName
                    if(printExpMenuSearchByName(fileName) == DO_EXP) {
                        if(search->exportResults(fileName) == EXP_CSV_FAIL) {
                            std::cout << "Fail to export results." << std::endl << std::endl;
                        }
                        else {
                            std::cout << "Results exported. " << std::endl << std::endl;
                        }
                    }
                }
                break;
            case MAIN_OPT2:
                // Clear the results container first
                search->clearResults();
                // Print the 'search by DBN' menu
                printMenuSearchByDBN(keyword);
                // Apply 'search by DBN' method
                if(search->searchMethod(SEARCH_BY_DBN, keyword) == RES_NOT_FOUND) {
                    std::cout << "No results were found!" << std::endl << std::endl;
                }
                else {
                    // Print the results on the screen
                    search->printResults();
                }
                break;
            case MAIN_OPT3:
                exit = true;
                break;
            default:
                exit = true;
                break;
        };
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

