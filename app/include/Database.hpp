#include <unordered_map>
#include <vector>
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

    std::vector<DatabaseRecord> searchByName(std::string name);
    DatabaseRecord searchByDbn(std::string dbn);

private:
    std::unordered_map<std::string, DatabaseRecord> records;
    void loadDatabase(std::string path);
};