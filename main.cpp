// Challenge C++ AISDigital

#include <iostream>
#include "school.h"
#include "presentation/menu.h"

int main(int argc, const char * argv[]) { 
    std::cout << "Challenge C++" << std::endl;

    while(true)
    {
        switch(print_menu())
        {
            case 1:
                search_by_name();
            break;
            case 2:
                search_by_dbn();
            break;
            case 3:
                return 0;
            break;
        }
    }

  return 0;
}

