#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <string>
#include <vector>

class DataEntry;

class DataWriter
{
    friend class DataWriterTest;

    static const std::string DEFAULT_OUTPUT_DIR;

    bool createFolder(const std::string& folderpath);

public:
    DataWriter();

    void createCSVFile(const std::string& filename,
                       const std::vector<DataEntry>& entries,
                       const std::string& folderpath = DEFAULT_OUTPUT_DIR);
};

#endif // DATAWRITER_H
