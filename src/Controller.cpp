#include "../include/Controller.h"

Controller::Controller(std::string fileSrc)
{
  m_csv = new CSVReader(fileSrc);
}

Controller::~Controller()
{
  delete(m_csv);
}

void Controller::InputString(std::string& storage)
{
  while(true)
  {
    std::getline(std::cin, storage);
    std::cin.clear();

    if(storage.size() > 0)
      break;
  }
}

bool Controller::SaveCSVFile(std::string filename, std::vector<std::vector<std::string>> elements)
{
  std::ofstream fileSaved;
  fileSaved.open("output/"+filename+".csv");

  if(fileSaved.is_open())
  {
    for(auto data: elements)
    {
      std::string dataLine;
      for(uint i=0;i<data.size();++i)
        dataLine += data[i] + (i == data.size()-1?"\n":",");
      fileSaved << dataLine;
    }

    fileSaved.close();
    return true;
  }

  fileSaved.close();
  return false;
}

bool Controller::SortFunction(std::vector<std::string> elementA, std::vector<std::string> elementB)
{
  std::set<std::string> sortStrings;
  sortStrings.insert(elementA[1]);
  sortStrings.insert(elementB[1]);

  return *sortStrings.begin() == elementA[1];
}

void Controller::SearchByName()
{
  std::cout << "\n\n===================================================\n";
  std::cout << "===================================================\n";
  std::cout << "\n[SEARCH BY NAME OPTION] Type the Name Searched: ";

  std::string input;
  InputString(input);

  std::cout << "\n\t[Results]: \n\n";

  std::vector<std::vector<std::string>> results;
  m_csv->SearchName(input, results);

  std::sort(results.begin(), results.end(), Controller::SortFunction);

  for(auto data: results)
  {
    std::cout<<"\t";
    for(uint i=0;i<data.size();++i)
      std::cout << data[i] << (i == data.size() - 1 ? "\n" : " | ");
  }

  while(true)
  {
    std::cout << "\nDo you want to save?(y/n) ";

    std::string answer;
    std::cin >> answer;
    std::cin.clear();

    if(answer == "y" || answer == "Y")
    {
      std::cout << "\nType the output filename: ";

      std::string filename;
      InputString(filename);

      if(!SaveCSVFile(filename, results))
      {
        answer = "x";
      }
      else
      {
        std::cout << "[OUTPUT SUCCESS] The file was saved!\n";
        break;
      }
    }
    else if(answer == "n" || answer == "N")
    {
      break;
    }
    else
    {
      std::cout << "Wrong answer try Again...\n\n";
    }
  }
}

void Controller::SearchByDBN()
{
  std::cout << "\n\n===================================================\n";
  std::cout << "===================================================\n";
  std::cout << "\n[SEARCH BY DBN] Type the DBN: ";

  std::string DBNSearched;
  InputString(DBNSearched);

  std::vector<std::string> result;
  m_csv->SearchDBN(DBNSearched, result);

  if(result.size() == 0)
  {
    std::cout << "\t[DBN SEARCH] NO RESULTS...\n";
    return;
  }

  std::cout<<"\t[DBN RESULT]:\n\t\t";
  for(uint i=0;i<result.size();++i)
    std::cout << result[i] << (i == result.size() - 1?"\n":" | ");
}

void Controller::Run()
{
  bool run = true;
  while(run)
  {
    std::cout<<"\n[ MENU ]===================================\n";
    std::cout<<"OPTIONS: \n";
    std::cout<<"\t[1]\tSEARCH BY NAME\n";
    std::cout<<"\t[2]\tSEARCH BY DBN\n";
    std::cout<<"\t[3]\tEXIT\n";
    std::cout<<"===========================================\n\n";

    std::cout<<"Select An Option: ";
    int option;
    std::cin >> option;
    std::cin.clear();

    switch (option)
    {
      case 1:
        SearchByName();
        break;
      case 2:
        SearchByDBN();
        break;
      case 3:
        run = false;
        std::cout<<"\n===========================================\n";
        std::cout << "\tBye!";
        std::cout<<"\n===========================================\n";
        break;
      default:
        std::cout<<"\n===========================================\n";
        std::cout << "\t[INPUT ERROR] Incorrect Input...";
        std::cout<<"\n===========================================\n";
        run = false;
    }

    if(!run)
      break;
  }
}
