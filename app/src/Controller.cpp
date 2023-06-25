#include "Controller.hpp"

Controller::Controller(std::string inputPath) : 
    db(inputPath) {}

Controller::~Controller() {}

/// @brief Run the application, retrieves and send data to View and Database classes.
void Controller::run() {
    int option;
    while(true) {
        this->view.printMenu();
        option = this->view.getUserOption();
        switch(option) {
            case 1: {
                std::string dbn = this->view.queryDbn();
                bool found;
                DatabaseRecord result = this->db.searchByDbn(dbn, found);
                if(found) {
                    this->view.printRecord(result);
                }
                else {
                    this->view.showWarningNotFound(dbn);
                }
                this->view.waitInputReturnToMenu();
                break;
            }
            case 2: {
                std::string schoolName = this->view.querySchoolName();
                bool found;
                std::vector<DatabaseRecord> results = this->db.searchByName(schoolName, found);
                if(found) {
                    for(int i = 0; i < results.size(); i++) {
                        this->view.printRecord(results[i]);
                    }
                    bool saveFile = this->view.querySaveFile();
                    if(saveFile) {
                        std::string outputFileName = this->view.querySaveFileName();
                        this->saveResultsToCsv(results, outputFileName);
                    }
                }
                else {
                    this->view.showWarningNotFound(schoolName);
                }
                this->view.waitInputReturnToMenu();
                break;
            }
            case 3: {
                this->view.showExitMsg();
                exit(0);
            }
            default: {
            }
        }
    }
}

/// @brief Write search results to a CSV file
/// @param results List of database records to save
/// @param fileName Output file name
void Controller::saveResultsToCsv(std::vector<DatabaseRecord> results, std::string fileName) {
    std::filesystem::create_directory("./output");
    std::ofstream saveFile("output/"+fileName);

    if(saveFile.is_open()) {
        saveFile << "DBN,School Name,Number of Test Takers,Critical Reading Mean,Mathematics Mean,Writing Mean\n";
        for(int i = 0; i < results.size(); i++) {
            saveFile << results[i].getDbn()+",";
            saveFile << results[i].getSchoolName()+",";
            saveFile << results[i].getTestTakers()+",";
            saveFile << results[i].getCriticalReadingMean()+",";
            saveFile << results[i].getMathMean()+",";
            saveFile << results[i].getWritingMean()+"\n";
        }
        saveFile.flush();
        saveFile.close();
    }
    else {
        this->view.showWarningOpenFile();
    }
}
