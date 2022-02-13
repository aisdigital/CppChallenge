// Challenge C++ AISDigital

#include <iostream>

#include "search.h"
#include "search_ui.h"

int main(int argc, const char * argv[]) { 
    Search *search = new Search();
    
    //Check if everything is fine
    if(!search->getStatus()) {
      std::cerr << "Fatal error." << endl;
    }
    else {
      std::cout << "Everything is fine." << endl << endl;
    }

    search->printResults();

    return 0;
}

