#include "MainMenu.hpp"

#include <iostream>

//---------------------------------------------------------------------------------------------

int MainMenu::Start()
{
  schoolsData.Load("./input/SAT__College_Board__2010_School_Level_Results.csv");
  
  bool execute = true;

  while (execute)
  {
    switch (ShowMenu())
    {
      case (SEARCH_BY_NAME):
      {
        SearchBySchoolName();
        break;
      }
      case (SEARCH_BY_DBN):
      {
        SearchBySchoolDBN();
        break;
      }
      case (EXIT_MENU): 
      {
        std::cout << "\nClosing program...";
        execute = false;
        break;
      }
      default:
      {
        std::cout << "\nInvalid input, choose another value!" << std::endl;
        break;
      }
    }
  }

  return 0;
}

//---------------------------------------------------------------------------------------------

int MainMenu::ShowMenu() const
{
  ShowOptionsMessage();
  const int input = GetUserInput();
  return input;
}

//---------------------------------------------------------------------------------------------

void MainMenu::SearchBySchoolName()
{
  std::cout << "\nInsert school name: ";
  std::string schoolName = GetLine();

  std::vector<std::shared_ptr<SchoolData>> schools = schoolsData.SeachBySchoolName(schoolName);
  ShowResults(schools);

  if (!schools.empty()) {
    StartSavingLooping(schools);
  }
}

//---------------------------------------------------------------------------------------------

void MainMenu::SearchBySchoolDBN()
{
  std::cout << "\nInsert school DBN: ";
  std::string DBN = GetLine();

  std::vector<std::shared_ptr<SchoolData>> schools = schoolsData.SeachBySchoolDBN(DBN);
  ShowResults(schools);
}

//---------------------------------------------------------------------------------------------

void MainMenu::ShowOptionsMessage() const
{
  std::cout << std::endl;
  std::cout << "1. Search data using school name" << std::endl;
  std::cout << "2. Search data using school DBN" << std::endl;
  std::cout << "3. Exit menu" << std::endl;
  std::cout << "\nChoose one of the options above: ";
}

//---------------------------------------------------------------------------------------------

void MainMenu::StartSavingLooping(
  const std::vector<std::shared_ptr<SchoolData>>& schools
) const
{
  std::cout << "\nDo you wish to save your search results? [y/n]: ";
  while (true)
  {
    std::string answer = GetLine();

    if (answer == "y") {
      SaveResults(schools);
      break;
    }
    else if (answer == "n") {
      break;
    }
    else {
      std::cout << "Type a valid answer!";
    }
  }
}

//---------------------------------------------------------------------------------------------

void MainMenu::SaveResults(
  const std::vector<std::shared_ptr<SchoolData>>& schools
) const
{
  std::cout << "\nInsert results filename: ";
  std::string fileName = GetLine();

  const bool statusOk = schoolsData.Save(fileName, schools);
  if (statusOk) {
    std::cout << "\nYour results where save to:  ./output/" << fileName << ".csv" << std::endl;
  }
}

//---------------------------------------------------------------------------------------------

void MainMenu::ShowResults(
  const std::vector<std::shared_ptr<SchoolData>>& schools
) const
{
  if (schools.empty()) {
    std::cout << "\nNo results where found!" << std::endl;
  }
  else {
    std::cout << std::endl;
    for (std::shared_ptr<SchoolData> school : schools) {
      std::cout << school->ToString() << std::endl;
    }
  }
}

//---------------------------------------------------------------------------------------------

std::string MainMenu::GetLine() const
{
  std::string input;
  std::getline(std::cin, input);
  return input;
}

//---------------------------------------------------------------------------------------------

int MainMenu::GetUserInput() const
{
  int input = 0;
  std::cin >> input;

  if (std::cin.fail())
  {
    input = -1;
  }

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return input;
};


//---------------------------------------------------------------------------------------------
