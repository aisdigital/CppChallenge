

#include "../include/datawriter.h"

#include <fstream>
#include <stdexcept>
#include <sstream>

#if __cplusplus >= 201703L
    #include <filesystem>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

#include "../include/dataentry.h"

const std::string DataWriter::DEFAULT_OUTPUT_DIR = "./output";

bool DataWriter::createFolder(const std::string &folderpath)
{
    bool ret = false;
#if __cplusplus >= 201703L
    ret = std::filesystem::create_directory(DEFAULT_OUTPUT_DIR);
#else
    ret = mkdir(folderpath.c_str(), S_IRWXU) != -1;
#endif
    return ret;
}

DataWriter::DataWriter()
{

}

void DataWriter::createCSVFile(const std::string &filename,
                               const std::vector<DataEntry> &entries,
                               const std::string &folderpath)
{
    static const std::string CSV_EXTENSION = ".csv";

    createFolder(folderpath);

    std::string filepath = folderpath + '/' + filename + CSV_EXTENSION;

    std::ofstream outputWriter;
    outputWriter.open(filepath);
    if (!outputWriter.is_open()) {
        throw std::runtime_error("ERROR: couldn't open file " + filepath);
    }

    // Write Header
    outputWriter << "DBN,"
                    "School Name,"
                    "Number of Test Takers,"
                    "Critical Reading Mean,"
                    "Mathematics Mean,"
                    "Writing Mean";
    outputWriter << std::endl;

    // Write Data Body
    for (auto& entry : entries) {
        outputWriter << entry << std::endl;
    }
    outputWriter.close();
}


