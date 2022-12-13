#include "readExcel.h"
void ReadExcel::readDataFromFile(const std::string &filePathInput)
{
    std::fstream file;
    file.open(filePathInput, std::ios::in);
    if(file.is_open())
    {
        int currentLineOfFile{1};
        std::string rawLineFromFile{};
        while(getline(file, rawLineFromFile))
        {
            if(currentLineOfFile == 1)
            {
              currentLineOfFile ++;
              continue;
            }
            listOfLinesFromFile.push_back(rawLineFromFile);
        } 
        file.close();
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }
}


std::list<std::string> ReadExcel::getListOfData()
{
    return listOfLinesFromFile;
}


void ReadExcel::getFileOnDir(std::map<int, std::string> &mapOfFiles){
     int inputFilesIndex {1};
    for(const auto &entry : std::filesystem::directory_iterator("./input/"))
    {
      mapOfFiles[inputFilesIndex] = entry.path();
      inputFilesIndex ++;
    };

    return;
}