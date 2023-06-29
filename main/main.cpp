// Challenge C++ AISDigital

#include <iostream>
#include <cstdlib>
#include "csv_parser.hpp"
#include "level_results.hpp"





void optionSearchBySchoolName(const LevelResults &levelResults)
{
  std::string schoolName{};
  std::cout << "\n1. Search for term...: ";
  std::cin >> schoolName;
  auto subTable = levelResults.queryBySchoolName(schoolName);
  if (subTable.empty())
  {
    std::cout << "\nNo schools with term " << schoolName << " found.\n";
  }
  else
  {
    std::cout << "\n"
              << subTable.size() << " schools found.\n\n";
    std::cout << "\nDBN | School Name | Number of Test Takers | Critical Reading Mean | Mathematics Mean | Writing Mean\n";
  
    for (auto &row : subTable)
    {
      for (auto &cell : row)
      {
        std::cout << cell << "    ";
      }
      std::cout << "\n"
                << std::endl;
    }
    std::string save{};
    std::cout << "\n Do you want to save this search to a file? yes or no \n";
    std::cin >> save;
    if (save == "yes")
    {
      std::cout << "\nPlease, inform the file name: ";
      std::string filename{};
      std::cin >> filename;
      if (!CSVParser::writeCSVFile(filename, subTable))
      {
        std::cout << "\nUnable to write file.\n";

      }

    }
    else if (save == "no")
    {
      std::cout << "\nReturning to main menu... \n";

    }
    else 
    {
      std::cout << "\nWrong option: " << save << "\n\n";
    }

  }
}

void optionSearchByDBN(const LevelResults &levelResults)
{
  std::string dbn;
  std::cout << "\n1. Search for DBN...: ";
  std::cin >> dbn;
  auto row = levelResults.queryByDBN(dbn);
  if (row.empty())
  {
      std::cout << "\n DBN " << dbn << " not found. \n" ;
  }
  else 
  {
    std::cout << "\n\nDBN | School Name | Number of Test Takers | Critical Reading Mean | Mathematics Mean | Writing Mean\n";

    for (auto &cell : row)
    {
      std::cout << cell << "    ";
    }
    std::cout << "\n"
              << std::endl;  
  }


}

int main(int argc, const char *argv[])
{
  static constexpr auto SEARCH_BY_NAME_CODE = "1";
  static constexpr auto SEARCH_BY_DBN_CODE = "2";
  static constexpr auto EXIT_CODE = "3";

  if (argc < 2)
  {
    // No filepath inputed
    std::cout << "File path not found. Did you input the file path?" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Challenge C++" << std::endl;

  LevelResults lr;
  {
    CSVParser loader;
    if (loader.loadCSV(std::string{argv[1]}))
    {

      lr.processCSVTable(loader.getCSVTable());
      // auto r = lr.queryBySchoolName("QUEENS");

      /*
      for (auto &row : r)
      {
        std::cout << row.size() << "\n";
        for (auto &cell : row)
        {
          std::cout << cell << "\n";
        }
        std::cout << "\n"
                  << std::endl;
      }
      */
      std::string code{""}; // Using string as code to avoid cin locking.
      while (code != EXIT_CODE)
      {
        std::cout << "\n1. Search by school name\n";
        std::cout << "2. Search by DBN\n";
        std::cout << "3. Exit\n\n";

        std::cin >> code;
        if (code == SEARCH_BY_NAME_CODE)
        {
          optionSearchBySchoolName(lr);
        }
        else if (code == SEARCH_BY_DBN_CODE)
        {
          optionSearchByDBN(lr);
        }
        else if (code == EXIT_CODE)
        {
          std::cout << "Exiting program..."
                    << "\n\n";
        }
        else
        {
          std::cout << "Wrong option: " << code << "\n\n";
        }
      }
    }
    else
    {
      std::cout << "Failed to load file " << argv[1] << ". Verify if the file exists or is in the correct CSV format." << std::endl;
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
