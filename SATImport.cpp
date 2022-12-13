#include "SATImport.h"
#include <algorithm>

void SATImport::formatRawDataFromFile(const std::list<std::string> &aux)
{
    std::string cellValue{};
    int cellFromRow {1};
    SATModel_st data;
    for(const auto &rawItem : aux)
    {
        std::stringstream str(rawItem);
        while(getline(str, cellValue, ','))
        {
            switch(cellFromRow)
            {
                case static_cast<int>(columnsOfSATFile::DBN):
                  data.DBN = cellValue;
                  break;
                case static_cast<int>(columnsOfSATFile::SCHOOL_NAME):
                  data.school_name = cellValue;
                  break;  
                case static_cast<int>(columnsOfSATFile::N_OF_TEST_TAKERS):
                  data.n_of_test_takers = cellValue;
                  break;
                case static_cast<int>(columnsOfSATFile::CRITICAL_READING_MEAN):
                  data.critical_read_mean = cellValue;
                  break;
                case static_cast<int>(columnsOfSATFile::MATHEMATICS_MEAN):
                  data.mathematics_mean = cellValue;
                  break;
                case static_cast<int>(columnsOfSATFile::WRITING_MEAN):
                  data.writing_mean = cellValue;
                  break;
                default:
                  break;
            }
            cellFromRow++;
        };
        listOfData.push_back(data);
        cellFromRow = 1;
    };
    return;
};

int SATImport::filterData(int field, std::string keyword)
{
  std::transform(keyword.begin(), keyword.end(),keyword.begin(), ::toupper);
    std::cout << keyword << std::endl;
    switch(field)
    {
        case static_cast<int>(columnsOfSATFile::DBN):
            for(const auto& itemOfList : listOfData)
            {
                if(itemOfList.DBN.compare(keyword) == 0)
                {
                    std::cout << itemOfList;
                    return 0;
                }        
            }
        break;
        case static_cast<int>(columnsOfSATFile::SCHOOL_NAME):
        {            
            int resultCount{0};
            for(const auto& itemOfList : listOfData)
            {
                if(itemOfList.school_name.find(keyword) != std::string::npos)
                {
                    resultCount ++;
                    std::cout << itemOfList;
                }        
            }
            return ((resultCount >= 1 ? 0 : -1));
        }    
        break;
        default:
            break;
    }
    return -1;
};