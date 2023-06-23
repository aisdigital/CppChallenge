#include "View.hpp"
#include "Database.hpp"

/*
Controller.hpp: this class is responsible to control the operation flow of the application, exchanging information between the View and Database
Author: Lucca Leão
Date: 23/06/2023
*/

class Controller {
public:
    Controller(std::string inputPath);
    ~Controller();

    void run();

private:
    View view;
    Database db;
};