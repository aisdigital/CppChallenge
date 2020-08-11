/**
 *  Challenge C++ AISDigital
 *
 *  @author Rafael Lima
 */


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


// DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean


/**
 * Read CSV File
 */
std::vector<std::string> readDatabaseFile(std::string filename)
{
    std::vector<std::string> datalist;
    std::ifstream inputFile;
    inputFile.open(filename.c_str());

    if(inputFile.is_open())
    {
        std::string line;
        while( std::getline(inputFile,line) )
        {
            datalist.push_back(line);
        }
        inputFile.close();
    }

    return datalist;
}

/**
 * Write CSV File
 */
int writeOutputFile(std::string filename)
{
    std::ofstream outputFile;
    outputFile.open(filename.c_str());

    outputFile << "";

    outputFile.close();

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

/**
 * User Interface
 */
int cli()
{
  char option = 'q';
  do
  {
      // Print Menu 
      std::cout << "\n      Challenge C++";
      std::cout << "\n╒═══════════════════════╕";
      std::cout << "\n│ (1) Search by Name    │";
      std::cout << "\n│ (2) Search by DBN     │";
      std::cout << "\n│ (q) Exit              │";
      std::cout << "\n╘═══════════════════════╛" << std::endl;
      
      // Read User Input
      std::cout << ">> Chose Option (1,2,[q]): ";
      std::cin >> option;
      
      // Evaluate Option
      if(option == '1')
      {
          std::string schoolName;
          char menuFileInput = 'n';
          
          // TODO Ask School Name
          std::cout << ">> School Name: ";
          std::cin >> schoolName;

          // Prompt user for write file
          std::cout << ">> Write output to a file? (y/[n])" << std::endl;
          std::cin >> menuFileInput;

          if(menuFileInput == 'y')
          {
              // Prompt User for file location
              std::string outputFileName = "report.txt";
              std::cout << "Name of output file: ";
              std::cin >> outputFileName;

              // Print to file
              std::vector<std::string> data = readDatabaseFile("input/SAT__College_Board__2010_School_Level_Results.csv");
              std::cout << searchBySchoolName(schoolName) << std::endl;
          }
          else
          {
              // Print to cout
              std::vector<std::string> data = readDatabaseFile("input/SAT__College_Board__2010_School_Level_Results.csv");
              for(std::vector<std::string>::iterator it = std::begin(data); it != std::end(data); ++it)
              {
                  std::cout << *it << "\n";
              }
          }

      }
      else if (option  == '2')
      {
          // TODO Ask DBN Code
          std::string dbn;

          // Read database and Find entry by DBN
          std::vector<std::string> data = readDatabaseFile("input/SAT__College_Board__2010_School_Level_Results.csv");
          for(std::vector<std::string>::iterator it = std::begin(data); it != std::end(data); ++it)
          {
              std::cout << *it << "\n";
          }

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


int main(int argc, const char * argv[]) { 

  // Run GUI
  cli();    

  return(0);
}

