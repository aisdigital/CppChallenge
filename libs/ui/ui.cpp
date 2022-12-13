#include <ui.h>

void UI::printLine()
{
    std::cout << "===================================================" << std::endl;
    return;
}

void UI::printMenu(const std::string& menuHeader, const std::map<int, std::string>& mapOfFiles)
{
  printLine();
  std::cout << menuHeader << std::endl;
  for(auto& mapKey : mapOfFiles)
  {
    std::cout << mapKey.first << " - " << mapKey.second << std::endl; 
  }

  std::cout << ": ";
  std::cin >> this->menuSelectedOption;

  printLine();

  return;
}
