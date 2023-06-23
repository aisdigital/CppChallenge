#include "Database.hpp"

Database::Database(std::string filePath) {
    this->loadDatabase(filePath);
}

Database::~Database() {}

std::vector<DatabaseRecord> Database::searchByName(std::string name) {
    std::vector<DatabaseRecord> records;
    return records;
}

DatabaseRecord Database::searchByDbn(std::string dbn) {

}

void Database::loadDatabase(std::string path) {

}
