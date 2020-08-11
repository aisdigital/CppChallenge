/**
 *  Challenge C++ AISDigital
 *
 *  @author Rafael Lima
 */


#include <iostream>
#include <vector>
#include <string>
#include <sstream>


// DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean


/**
 * Read CSV File
 */
int readDatabaseFile(std::string filename)
{
    return 0;
}


/**
 *
 */
std::string searchBySchoolName(std::string schoolName)
{
    readDatabaseFile("input/SAT__College_Board__2010_School_Level_Results.csv");

    return "";
}

/**
 *
 */
std::string searchByDBN(std::string dbn)
{
    readDatabaseFile("input/SAT__College_Board__2010_School_Level_Results.csv");

    return "";
}

int main(int argc, const char * argv[]) { 

  char option = 'q';
  do
  {
      // Print Menu 
      std::cout << "\n     Challenge C++";
      std::cout << "\n|=======================|";
      std::cout << "\n| (1) Search by Name    |";
      std::cout << "\n| (2) Search by DBN     |";
      std::cout << "\n| (q) Exit              |";
      std::cout << "\n|=======================|";
      std::cout << "\n| Type Option (1,2,[q]) |";
      std::cout << "\n|=======================|" << std::endl;
      
      // Read User Input
      std::cin >> option;
      
      // Evaluate Option
      if(option == '1')
      {
          std::string schoolName;
          char menuFileInput = 'n';
          
          // TODO Ask School Name
          std::count << "\t School Name: ";
          std::cin >> schoolName;

          // Prompt user for write file
          std::cout << "Write output to a file? (y/[n])" << std::endl;
          std::cin >> menuFileInput;

          if(menuFileInput == 'y')
          {
              std::string outputFileName = "report.txt";
              // Prompt User for file location
              std::cout << "Name of output file: "
              std::in >> outputFileDir;

              // Print to file
              std::cout << searchBySchoolName(schoolName) << std::endl;
          }
          else
          {
              // Print to cout
              std::cout << searchBySchoolName(schoolName) << std::endl;
          }

      }
      else if (option  == '2')
      {
          // TODO Ask DBN Code
          std::string dbn;

          //  
          std::cout << searchByDBN(dbn) << std::endl;
      }
      else if (option == 'q')
      {
          return(0);
      }
      else
      {
          std::cout << "Invalid Option!" << std::endl;
      }

    
  } while(option != 'q');
      

  return(0);
}

