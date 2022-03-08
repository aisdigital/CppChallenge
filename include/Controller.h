#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>

#include "CSVReader.h"

class Controller
{
private:
  CSVReader* m_csv;

  void InputString(std::string& storage);
  bool SaveCSVFile(std::string filename, std::vector<std::vector<std::string>> elements);

  static bool SortFunction(std::vector<std::string> elementA, std::vector<std::string> elementB);
  void SearchByName();
  void SearchByDBN();

public:
  Controller(std::string fileSrc);
  ~Controller();

  void Run();
};
