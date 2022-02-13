#include "../include/output.hpp"

void saveCSVOutput(const std::string schoolName, const std::vector<Entry> &entriesSchoolName, const std::string DBN, const Entry &entryDBN)
{
    //! terminal menu
    int option = 0;
    char fileName[256];
    std::cout << "Do you want to save the results in a .csv file?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
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

    //! create .csv file descriptor
    std::ofstream csvFile;
    //! standard output folder
    std::string outputFolder = "./output/";

    switch (option)
    {
    //! save in .csv file
    case 1:
        std::cout << "Please input the .csv file name: " << std::endl;
        //! get 256 chars from std::cin
        std::cin.getline(fileName, 256);
        //! open file with given file name
        csvFile.open(outputFolder.append(fileName).append(".csv"));
        //! save searchBySchoolName query in .csv format
        if (DBN.empty())
        {
            std::cout << "searchBySchoolName" << std::endl;
            csvFile << "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n";
            for (int i = 0; i < entriesSchoolName.size(); i++)
            {
                entriesSchoolName[i].printEntryInCSV(csvFile);
            }
        }
        //! save searchByDBN query in .csv format
        else if (schoolName.empty())
        {
            csvFile << "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n";
            entryDBN.printEntryInCSV(csvFile);
        }
        csvFile.close();
        std::cout << "\nFile " << fileName << ".csv saved successfuly!"
                  << std::endl;
        break;

    //! don't save in .csv file
    case 2:
        break;

    default:
        std::cout << "Invalid option! Try again." << std::endl;
        break;
    }
    return;
}
