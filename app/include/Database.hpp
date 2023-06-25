#include <unordered_map>
#include <vector>
#include <functional>
#include <future>
#include <thread> 
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "DatabaseRecord.hpp"

/*
Database.hpp: this class is responsible for holding and manipulating (search operations) the data from the CSV file
Author: Lucca Leão
Date: 23/06/2023
*/

class Database {
public:
    Database(std::string filePath);
    ~Database();

    std::vector<DatabaseRecord> searchByName(std::string name, bool& found);
    DatabaseRecord searchByDbn(std::string dbn, bool& found);

private:
    void startDatabase();
    void parseCsv(std::promise<std::unordered_map<std::string, DatabaseRecord>> promise);

    std::unordered_map<std::string, DatabaseRecord> records;
    std::string path;

};