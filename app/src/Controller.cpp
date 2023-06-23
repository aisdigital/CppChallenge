#include "Controller.hpp"

Controller::Controller(std::string inputPath) : 
    db(inputPath) {}

Controller::~Controller() {}

void Controller::run() {
    int option;
    while(true) {
        this->view.printMenu();
        option = this->view.getUserOption();
        switch(option) {
            case 1:
                std::cout << "Option 1" << std::endl;
                break;
            case 2:
                std::cout << "Option 2" << std::endl;
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                exit(0);
            default:
                std::cout << "Please enter a valid option." << std::endl;
        }
    }
}