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

void Controller::saveResultsToCsv(std::string fileName) {
    
}
