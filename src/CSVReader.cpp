#include "../include/CSVReader.h"

CSVReader::CSVReader(std::string fileSrc)
{
  LoadData(fileSrc);
}

CSVReader::~CSVReader()
{
  m_csvFile.close();
}

void CSVReader::LoadData(std::string fileSrc)
{
  m_csvFile.open(fileSrc);
  if(m_csvFile.is_open())
  {
    std::string currentLine;

    while(std::getline(m_csvFile, currentLine))
    {
      std::vector<std::string> currentData;
      std::vector<std::string> DBNStorage;

      DecomposeData(currentLine, currentData, DBNStorage);
      InsertData(currentData, DBNStorage);
    }
  }
  else
  {
    std::cout<<"[LOAD ERROR] CSV File Not Founded...\n";
  }
}

void CSVReader::DecomposeData(std::string data, std::vector<std::string>& dataStorage, std::vector<std::string>& DBNStorage)
{
  std::stringstream formatedData(data);
  std::string element;

  while(getline(formatedData, element, ','))
  {
    // If has many DBNs you have to decompose.
    if(dataStorage.size() == 0 && element.find("/") != std::string::npos)
    {
        auto delimiter = element.find("/");

        DBNStorage.push_back(element.substr(0, delimiter));
        DBNStorage.push_back(element.substr(delimiter + 1, element.size()));
    }
    else if(dataStorage.size() == 0)
    {
      DBNStorage.push_back(element);
    }

    dataStorage.push_back(element);
  }
}

void CSVReader::InsertData(std::vector<std::string> newData, std::vector<std::string> DBNStorage)
{
  if(newData.size() > 0 && newData[0] != "DBN")
  {
    m_csvData.push_back(newData);

    // Can Handle With Multiple DBNs to the same data
    for(auto DBNItem: DBNStorage)
      m_DBNIndex[DBNItem] = m_csvData.size()-1;
  }
}

void CSVReader::PrintAllData()
{
  for(auto data: m_csvData)
  {
    std::cout<<data.size()<<" ";
    for(uint i = 0; i < data.size(); ++i)
      std::cout<<data[i]<<(i==data.size()-1?"":",");
    std::cout<<"\n";
  }
}

char CSVReader::toLower(char element)
{
  if(element >= 'A' && element <= 'Z')
    return 'a'+abs('A'-element);
  return element;
}

bool CSVReader::IsStringInside(std::string stringAnalised, std::string stringSearched)
{
  // O(n)
  if(stringAnalised.size() < stringSearched.size())
    return false;

  uint matchPos = 0;
  for(auto element: stringAnalised)
  {
    if(matchPos == stringSearched.size())
      return true;

    if(toLower(element) == toLower(stringSearched[matchPos]))
      matchPos += 1;
    else
    {
      matchPos = 0;
      if(toLower(element) == toLower(stringSearched[matchPos]))
        matchPos = 1;
    }
  }

  return false;
}

void CSVReader::SearchName(std::string schoolName, std::vector<std::vector<std::string>>& storage)
{
  for(auto data: m_csvData)
  {
    if(IsStringInside(data[1], schoolName))
      storage.push_back(data);
  }
}

void CSVReader::SearchDBN(std::string DBNValue, std::vector<std::string>& storage)
{
  if(m_DBNIndex.find(DBNValue) != m_DBNIndex.end())
  {
    uint dataIndex = m_DBNIndex[DBNValue];
    storage = m_csvData[dataIndex];
  }
}
