// Challenge C++ AISDigital

#include <iostream>
#include "school.h"
#include "presentation/menu.h"
#include "helper/file.h"
#include "school_manipulation.h"

const int SKIP_FIRST_ITEM = 1;

int main(int argc, const char * argv[])
{
    std::cout << "Challenge C++" << std::endl;
    vector<string> data = read_file("./input/SAT__College_Board__2010_School_Level_Results.csv");
    vector<school*> schools = build_school_list(vector<string>(data.begin() + SKIP_FIRST_ITEM, data.end()));
    unordered_map<string, school*> schools_fast_lookup;

    build_school_fast_lookup(schools, schools_fast_lookup);

    while(true)
    {
        switch(print_menu())
        {
            case 1:
                search_by_name();
            break;
            case 2:
                search_by_dbn(schools_fast_lookup);
            break;
            case 3:
                return 0;
            break;
        }
    }

  return 0;
}

