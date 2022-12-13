// Challenge C++ AISDigital
#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <thread>
#include <sstream>
#include "./SATImport.h"
#include "ui.h"



TEST(FilterTest, validDBM)
{
  const std::string validDBMKeyword = "01M292";
  SATImport testObj;
  EXPECT_EQ(testObj.filterData(1,validDBMKeyword), -1);
}
TEST(FilterTest, invalidDBM)
{
  const std::string invalidDBMKeyword = "WRONGDBM";
  SATImport testObj;
  EXPECT_EQ(testObj.filterData(3,invalidDBMKeyword), -1);
}
TEST(FilterTest, invalidOption)
{
  SATImport testObj;
  EXPECT_EQ(testObj.filterData(3), -1);
}


int main() { 
  UI interface;
  
  std::map<int, std::string> filesMap;
  ReadExcel readFile_obj;
  readFile_obj.getFileOnDir(filesMap);
  interface.printFilesMenu(filesMap);

  int selectedFileIndex {-1};
  interface.getOptionInput(selectedFileIndex);
  
  interface.printStartFileRead(filesMap.at(selectedFileIndex));
  
  std::thread read_file_thread(&ReadExcel::readDataFromFile, &readFile_obj,static_cast<std::string>(filesMap.at(selectedFileIndex)));
  read_file_thread.join();

  std::list<std::string> rawData = readFile_obj.getListOfData();
  SATImport satFile;
  satFile.formatRawDataFromFile(rawData);
  interface.printSATFilterMenu();

  int filterOption {-1};
  interface.getOptionInput(filterOption);

  if(filterOption >= 1 && filterOption <=2)
  {
    std::string filterKeyword{""};
    std::cout << "===============================================================" << std::endl;
    std::cout << "Please Inform the Keyword to Filter:";
    getline(std::cin,filterKeyword);
    satFile.filterData(filterOption,filterKeyword);
  }
  
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

