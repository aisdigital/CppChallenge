#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>
#include <string>

#include "SchoolDataMap.hpp"

enum MenuOptions
{
  SEARCH_BY_NAME = 1,
  SEARCH_BY_DBN = 2,
  EXIT_MENU = 3,
  INVALID_VALUE = -1
};

class MainMenu
{
  public:
    MainMenu() = default;

    virtual ~MainMenu() = default;

    int Start();

    int ShowMenu() const;

    void ShowOptionsMessage() const;

    void SearchBySchoolName();

    void SearchBySchoolDBN();

    void StartSavingLooping(
      const std::vector<std::shared_ptr<SchoolData>>& schools
    ) const;

    void SaveResults(
      const std::vector<std::shared_ptr<SchoolData>>& schools
    ) const;

    void ShowResults(
      const std::vector<std::shared_ptr<SchoolData>>& schools
    ) const;

    int GetUserInput() const;

    std::string GetLine() const;

  private:
    SchoolDataMap schoolsData;
};

#endif