#include "Database.hpp"

Database::Database(std::string filePath) :
    path(filePath) {
    this->startDatabase();
}

Database::~Database() {}

/// @brief Returns all SAT records containing @name
/// @param name 
/// @return 
std::vector<DatabaseRecord> Database::searchByName(std::string name) {
    std::vector<DatabaseRecord> data;
    return data;
}

DatabaseRecord Database::searchByDbn(std::string dbn) {
    auto found = records.find(dbn);
    return found->second;
}

/// @brief Starts database while loading data from CSV file asynchronously in a new thread
/// @param path: CSV file path where data is stored
void Database::startDatabase() {
    std::promise<std::unordered_map<std::string, DatabaseRecord>> databasePromise;
    std::future<std::unordered_map<std::string, DatabaseRecord>> future = databasePromise.get_future();
    std::thread dataLoadingThread(&Database::parseCsv, this, std::move(databasePromise));  // Loads CSV data in separate thread
    dataLoadingThread.detach();

    std::unordered_map<std::string, DatabaseRecord> data = future.get();  // Retrieve promised data
    this->records = data;
}

/// @brief Parse CSV file and builds the DatabaseRecord data structure for each row
/// @param promise Promise that needs to be filled with the database values
void Database::parseCsv(std::promise<std::unordered_map<std::string, DatabaseRecord>> promise) {
    std::unordered_map<std::string, DatabaseRecord> data;
    std::ifstream reader(this->path);
    if(reader.is_open()) {
        std::string line;
        std::getline(reader, line); // Header row
        
        while(std::getline(reader, line)) {
            std::stringstream ss;
            std::vector<std::string> tokens;
            ss << line;
            while(ss >> std::ws) {
                std::string cell;
                if(ss.peek() == '"') {      // Quoted cell
                    ss >> std::quoted(cell);
                    std::string discard;
                    std::getline(ss, discard, ',');
                }
                else {                      // Unquoted cell
                    std::getline(ss, cell, ',');
                }
                tokens.push_back(cell);
            }
            DatabaseRecord record(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);
            data.insert(std::make_pair(tokens[0],record));
        }
    }
    else {
        // Keep promise even if file is not found
        promise.set_value(data);
        return;
    }
    // Keep promise!
    promise.set_value(data);
}