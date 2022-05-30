#ifndef DATAREADER_H
#define DATAREADER_H

#include <string>
#include <vector>

class DataEntry;

class DataReader
{
    friend class DataReaderTest;

    std::string m_filepath;

    std::vector<std::string> m_attributesOrder;

    void readAttributeOrder(const std::string& firstLine);

    void convertLinesToEntries(const std::vector<std::string>& lines,
                               std::vector<DataEntry>& entries);

    DataEntry convertLineToEntry(const std::string& line);

public:
    static const std::string DEFAULT_FILEPATH;

    static const char DEFAULT_SEPARATOR;

    DataReader();

    DataReader(const std::string& filepath);

    std::vector<DataEntry> readData();
};

#endif // DATAREADER_H
