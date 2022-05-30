// Challenge C++ AISDigital

#include <iostream>

#include <thread>
#include <map>
#include <memory>
#include <mutex>

#include "include/dataentry.h"
#include "include/dataprocessor.h"
#include "include/datareader.h"
#include "include/datawriter.h"
#include "include/optionmenu.h"

void prepareCSV(std::shared_ptr<std::map<std::string, DataEntry>> dataPtr)
{
    static std::once_flag callFlag;

    if (dataPtr == nullptr) {
        return;
    }

    std::call_once(callFlag,
                   [](std::shared_ptr<std::map<std::string, DataEntry>> dataMap)
    {
        DataReader reader;
        DataProcessor processor;
        std::vector<DataEntry> rawEntries;
        try {
            rawEntries = reader.readData();
        } catch (std::runtime_error& err) {
            std::cerr << err.what() << std::endl
                      << "Possible fix: Make sure the program is running at the correct datapath (./CppChallenge or ./CppChallenge/build)."
                      << std::endl;
            std::exit(1);
        }
        *dataMap = processor.processRawEntries(rawEntries);
    },  dataPtr);
}

int main(int argc, const char* argv[]) {
    std::cout << "Challenge C++" << std::endl;

    OptionMenu optionSelector;
    DataProcessor processor;
    DataWriter writer;
    auto data = std::make_shared<std::map<std::string, DataEntry>>();
    auto searchedSchools = std::vector<DataEntry>();
    std::string saveFilename;
    std::string searchTerm;

    do {
        std::thread readCSVThread(prepareCSV, data);
        optionSelector.viewInitialMenu();
        optionSelector.readInitialOption();
        readCSVThread.join();
        switch (optionSelector.getOptionSelected()) {
            case OptionStates::NAME_SEARCH:
                optionSelector.viewSubstringInputMenu();
                optionSelector.readSearchTerm(searchTerm);
                searchedSchools = processor.searchDataBySubString(searchTerm, *data);
                optionSelector.viewDataEntries(searchedSchools);
                if (!searchedSchools.empty()) {
                    optionSelector.viewSaveMenu();
                    if (optionSelector.readSaveOption()) {
                        optionSelector.viewFileSaveMenu();
                        optionSelector.readSaveFilename(saveFilename);
                        try {
                            writer.createCSVFile(saveFilename, searchedSchools);
                        } catch(std::runtime_error& err) {
                            std::cerr << "OPERATION NOT POSSIBLE: " << err.what() << std::endl;
                        }
                    }
                }
                break;
            case OptionStates::DBN_SEARCH:
                optionSelector.viewDBNInputMenu();
                optionSelector.readSearchTerm(searchTerm);
                searchedSchools = processor.searchDataByDBN(searchTerm, *data);
                optionSelector.viewDataEntries(searchedSchools);
                break;
            case OptionStates::EXIT_SEARCH:
            default:
                break;
        }

    } while (optionSelector.getOptionSelected() != OptionStates::EXIT_SEARCH);

    return 0;
}

