#include "../include/dataprocessor.h"

#include <algorithm>
#include <memory>
#include <sstream>
#include <thread>

#include "../include/dataentry.h"
#include "../include/nameprocessor.h"

DataProcessor::DataProcessor()
{
}

std::map<std::string, DataEntry> DataProcessor::processRawEntries(const std::vector<DataEntry> &entries)
{
    auto addEntryToMap =
            [](
            const std::string& entryDBN,
            const DataEntry& entry,
            std::map<std::string, DataEntry>& mapData) -> void
    {
        // Eliminate duplicates by keeping the entry with more data.
        if (mapData.find(entryDBN) == mapData.end()) {
            mapData[entryDBN] = entry;
        } else {
            if ((entry.isFull() && !mapData[entryDBN].isFull()) ||
                   (entry.getTestTakers() > mapData[entryDBN].getTestTakers())) {
                mapData[entryDBN] = entry;
            }
        }
    };

    std::map<std::string, DataEntry> mapData;
    for (const auto& entry : entries) {
        // Split entries with more than one DBN into multiple entries
        auto entryDBN = entry.getDBN();
        auto splitPos = entryDBN.find('/');
        while (splitPos != std::string::npos) {
            auto partialDBN = entryDBN.substr(0, splitPos);
            entryDBN.erase(0, splitPos + 1);
            if (entryDBN.length() > 0) {
                entryDBN.push_back('/');
            }
            // Add as new entry
            DataEntry newEntry = entry;
            newEntry.setAttribute(DataAttribute::DBNValue, partialDBN);
            addEntryToMap(partialDBN, newEntry, mapData);
            splitPos = entryDBN.find('/');
        }
        // Add Entry
        addEntryToMap(entry.getDBN(), entry, mapData);
    }
    return mapData;
}

std::vector<DataEntry> DataProcessor::searchDataByDBN(const std::string &DBNvalue,
                                        const std::map<std::string, DataEntry> &data)
{
    NameProcessor processor;
    auto searchDBN = DBNvalue;
    processor.capitalizeLetters(searchDBN);

    std::vector<DataEntry> entries;

    if (data.find(searchDBN) != data.end()) {
        entries.push_back(data.at(searchDBN));
    }
    return entries;
}

std::vector<DataEntry> DataProcessor::searchDataBySubString(const std::string &substring,
                                                    const std::map<std::string, DataEntry> &data)
{
    std::vector<DataEntry> entries;

    // Keep a hardware thread to this thread.
    unsigned nThreads =  std::thread::hardware_concurrency() - 1;
    if (nThreads > 2) {
        unsigned batchSize = data.size() / nThreads;
        unsigned batchRemain = data.size() % nThreads;

        // Lambda to search entries with names containing the substring
        auto addEntriesBySubString =
                [](
                const size_t threadCounter,
                const std::string &substr,
                const std::map<std::string, DataEntry> &dataMap,
                size_t start,
                size_t end,
                std::shared_ptr<std::vector<std::vector<DataEntry>>> sharedEntries
                ) -> void
        {
            if (end > start && sharedEntries != nullptr) {
                NameProcessor processor;

                auto iterStart = std::map<std::string, DataEntry>::const_iterator();
                auto iterEnd = std::map<std::string, DataEntry>::const_iterator();
                iterStart = dataMap.begin();
                iterEnd = dataMap.begin();
                std::advance(iterStart, start);
                std::advance(iterEnd, end);
                for (auto iter = iterStart; iter != iterEnd && iter != dataMap.end(); iter++) {
                     if (processor.hasSubString(iter->second.getTreatedName(), substr)) {
                         sharedEntries->at(threadCounter).push_back(iter->second);
                     }
                }
            }
        };

        // Populate threads to search for entries separatelly.
        std::vector<std::thread> threads;
        auto threadsSharedEntries =
                std::make_shared<std::vector<std::vector<DataEntry>>>(nThreads + 1);
        size_t startIndex;
        for (size_t i = 0; i < nThreads; i++) {
            startIndex = i * batchSize;
            threads.push_back(std::thread(addEntriesBySubString,
                                          i,
                                          substring,
                                          data,
                                          startIndex,
                                          startIndex + batchSize,
                                          threadsSharedEntries));
        }

        // Work remaining entries in this thread
        startIndex = nThreads * batchSize;
        addEntriesBySubString(
                    nThreads , substring, data, startIndex, startIndex + batchRemain,
                    threadsSharedEntries);

        // Merge all threads work
        for (auto& thread : threads) {
            thread.join();
        }
        for (auto& entriesFromThread : *threadsSharedEntries) {
            if (!entriesFromThread.empty()) {
                entries.insert(entries.end(), entriesFromThread.begin(), entriesFromThread.end());
                entriesFromThread.clear();
            }
        }
        threadsSharedEntries->clear();
    } else {
        NameProcessor processor;
        for (auto iter = data.begin(); iter != data.end(); iter++) {
            if (processor.hasSubString(iter->second.getTreatedName(), substring)) {
                entries.push_back(iter->second);
            }
        }
    }

    // Sort entries by name
    std::sort(entries.begin(), entries.end(), [](const DataEntry& entryA, const DataEntry& entryB)
    {
       return (entryA.getTreatedName() < entryB.getTreatedName());
    });

    return entries;
}
