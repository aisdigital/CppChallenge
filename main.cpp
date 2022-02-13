// Challenge C++ AISDigital

#include "include/output.hpp"
#include "include/query.hpp"
#include "include/storage.hpp"

int main(int argc, const char *argv[])
{
  //! read CSV file
  std::ifstream file("./input/SAT__College_Board__2010_School_Level_Results.csv");
  std::istream &fileDescriptor = file;
  //! store data from CSV file in memory
  std::vector<std::vector<std::string>> data = readCSV(fileDescriptor);

  //! terminal menu
  int option = 0;
  char key[256];
  std::vector<Entry> entriesSchoolName = {};
  Entry entryDBN = {};
  do
  {
    std::cout << "\nMain Menu" << std::endl;
    std::cout << "1 - Search By School Name" << std::endl;
    std::cout << "2 - Search By DBN" << std::endl;
    std::cout << "3 - Quit" << std::endl;
    std::cout << "Please choose an option: " << std::endl;
    std::cin >> option;
    //! avoid infinite loop std::cin
    if (std::cin.fail())
    {
      std::cout << "Invalid option! Try again.\n";
      //! get rid of failure state
      std::cin.clear();
    }
    //! clean std::cin buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option)
    {
    //! search by school name
    case 1:
      std::cout << "Please input a School Name: " << std::endl;
      //! get 256 chars from std::cin
      std::cin.getline(key, 256);
      //! clear vector for new query
      entriesSchoolName.clear();
      searchBySchoolName(data, key, entriesSchoolName);
      if (!entriesSchoolName.empty())
      {
        saveCSVOutput(key, entriesSchoolName, {}, {});
      }

      break;

    //! search by DBN
    case 2:
      std::cout << "Please input a DBN: " << std::endl;
      //! get 256 chars from std::cin
      std::cin.getline(key, 256);
      searchByDBN(data, key, entryDBN);
      if (!entryDBN.empty())
      {
        saveCSVOutput({}, {}, key, entryDBN);
      }
      break;

    //! exit
    case 3:
      break;

    default:
      std::cout << "Invalid option! Try again." << std::endl;
      break;
    }

  } while (option != 3);

  return 0;
}
