  #include "searchmenu.h"
  #include <iostream>

  using std::iostream;

  SearchMenu::SearchMenu()
  {
      m_search = new Search();
  }
  
  SearchMenu::~SearchMenu()
  {
      
  }

  void SearchMenu::showMenu()
  {
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Search by name" << std::endl;
    std::cout << "2 - Search by DBN" << std::endl;
    std::cout << "3 - Exit" << std::endl;

    int input = 0;
    std::cin >> input;
    manageSearch(input);
  }

  
  void SearchMenu::manageSearch(int searchMode)
  {
    string input;
    vector<string> result;
    switch(searchMode)
    {
    case SEARCH_BY_NAME_MODE:
        std::cout << "Search by name: ";
        std::cin >> input;
        result = m_search->searchName(input);
        m_search->showResult(result);
        break;
    case SEARCH_BY_DBN_MODE:
        std::cout << "Search by dbn: ";
        std::cin >> input;
        m_search->searchDbn(input);
        break;
    case EXIT_PROGRAM:
        std::cout << "Exit" << std::endl;
        break;
    default:
        break;
    }
  }