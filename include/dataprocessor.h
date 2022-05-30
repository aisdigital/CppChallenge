#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <map>
#include <string>
#include <vector>

class DataEntry;

class DataProcessor
{
public:
    DataProcessor();

    std::map<std::string, DataEntry> processRawEntries(const std::vector<DataEntry>& entries);

    std::vector<DataEntry> searchDataByDBN(const std::string& DBNvalue,
                                const std::map<std::string, DataEntry>& data);

    std::vector<DataEntry> searchDataBySubString(const std::string& substring,
                                                 const std::map<std::string, DataEntry>& data);
};

#endif // DATAPROCESSOR_H
