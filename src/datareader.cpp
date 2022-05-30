

#include "../include/datareader.h"

#include "../include/dataentry.h"
#include "../include/nameprocessor.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <memory>

const std::string DataReader::DEFAULT_FILEPATH = "./input/SAT__College_Board__2010_School_Level_Results.csv";

const char DataReader::DEFAULT_SEPARATOR = ',';

void DataReader::readAttributeOrder(const std::string &firstLine)
{
    std::stringstream ss(firstLine);
    std::string attributeAsStr;
    while( std::getline(ss, attributeAsStr, DEFAULT_SEPARATOR)) {
        m_attributesOrder.push_back(attributeAsStr);
    }

}

void DataReader::convertLinesToEntries(const std::vector<std::string> &lines,
                                       std::vector<DataEntry> &entries)
{
    entries.clear();

    // Keep a hardware thread to this thread.
    unsigned nThreads =  std::thread::hardware_concurrency() - 1;
    if (nThreads > 2) {
        unsigned batchSize = lines.size() / nThreads;
        unsigned batchRe = lines.size() % nThreads;

        // Lambda to Convert part of the lines into entries
        auto partialConversion =
                [this](const std::vector<std::string> &allLines,
                       const size_t start,
                       const size_t end,
                       std::shared_ptr<std::vector<DataEntry>> partialEntriesPtr) -> void
        {
            if (end > start && partialEntriesPtr != nullptr) {
                for (size_t i = start; i < end && i < allLines.size(); i++) {
                    partialEntriesPtr->at(i) = convertLineToEntry(allLines[i]);
                }
            }
        };

        // Populate the threads to fill part of the lines separatelly
        std::vector<std::thread> threads;
        size_t startIndex;
        std::shared_ptr<std::vector<DataEntry>> allPartialEntries;
        allPartialEntries = std::make_shared<std::vector<DataEntry>>(nThreads * batchSize);
        for (unsigned i = 0; i < nThreads; i++) {
            startIndex = i * batchSize;
            threads.push_back(std::thread(partialConversion,
                              lines,
                              startIndex,
                              startIndex + batchSize,
                              allPartialEntries));
        }
        // Work remaining lines in this thread
        startIndex = nThreads * batchSize;
        for (size_t i = startIndex; i < startIndex + batchRe && i < lines.size(); i++) {
            entries.push_back(convertLineToEntry(lines[i]));
        }

        // Merge all threads work
        for (auto& thread : threads) {
            thread.join();
        }
        entries.insert(entries.end(), allPartialEntries->begin(), allPartialEntries->end());
        allPartialEntries->clear();
    } else {
        for (const auto& line : lines) {
            entries.push_back(convertLineToEntry(line));
        }
    }
}

DataEntry DataReader::convertLineToEntry(const std::string &line)
{
    DataEntry entry;

    std::stringstream ss(line);
    std::string attributeValue;
    for (size_t i = 0;
         i < m_attributesOrder.size() && std::getline(ss, attributeValue, DEFAULT_SEPARATOR);
         i++) {
        auto attribute = convertStrToDataAttribute(m_attributesOrder[i]);
        entry.setAttribute(attribute, attributeValue);
    }

    return entry;
}

DataReader::DataReader() :
    m_filepath(DataReader::DEFAULT_FILEPATH)
{
}

DataReader::DataReader(const std::string& filepath) :
    m_filepath(filepath)
{
}

std::vector<DataEntry> DataReader::readData()
{
    // Open File
    std::ifstream csvFileReader;
    csvFileReader.open(m_filepath);
    if (!csvFileReader.is_open()) {
        // Try again at the folder parent to correct datapath issues.
        csvFileReader.open('.' + m_filepath);
        if (!csvFileReader.is_open()) {
            throw std::runtime_error("ERROR:" + m_filepath + " file not found.");
        }
    }

    // Read 1st Line to Obtain Attribute Order
    std::string firstLine;
    std::getline(csvFileReader, firstLine);
    if (firstLine.empty()) {
        throw std::runtime_error("ERROR:" + m_filepath + " file is empty.");
    }
    readAttributeOrder(firstLine);

    // Read Other Lines & Close
    std::string line;
    std::vector<std::string> lines;
    while(getline(csvFileReader, line)) {
        lines.push_back(line);
    }
    csvFileReader.close();

    // Convert Lines to DataEntry
    std::vector<DataEntry> entries;
    convertLinesToEntries(lines, entries);

    return entries;
}
