#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

class CSVReader
{
private:
  std::ifstream m_csvFile;

  std::vector<std::vector<std::string>> m_csvData;
  std::map<std::string, uint> m_DBNIndex;

  void LoadData(std::string fileSrc);
  void DecomposeData(std::string data, std::vector<std::string>& dataStorage, std::vector<std::string>& DBNStorage);
  void InsertData(std::vector<std::string> newData, std::vector<std::string> DBNStorage);

  char toLower(char element);
  bool IsStringInside(std::string stringAnalised, std::string stringSearched);

public:
  CSVReader(std::string fileSrc);
  ~CSVReader();

  void PrintAllData();
  void SearchName(std::string schoolName, std::vector<std::vector<std::string>>& storage);
  void SearchDBN(std::string DBNValue, std::vector<std::string>& storage);
};
