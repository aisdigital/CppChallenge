#include "Database.hpp"

Database::Database(std::string filePath) :
    path(filePath) {
    this->startDatabase();
}

Database::~Database() {}

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
        promise.set_value(data);  // Keep promise even if file is not found
        return;
    }
    promise.set_value(data);      // Keep promise!
}

/// @brief Search and returns all DatabaseRecords where school name contains the query string
/// @param name Query string
/// @param found Output parameter that represents if a search result was found
/// @return vector of DatabaseRecord sorted by school name
std::vector<DatabaseRecord> Database::searchByName(std::string name, bool& found) {
    std::vector<DatabaseRecord> searchResults;
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){ return std::tolower(c); });

    for(auto it : this->records) {
        std::string schoolName = it.second.getSchoolName();
        std::transform(schoolName.begin(), schoolName.end(), schoolName.begin(), [](unsigned char c){ return std::tolower(c); });
        if(schoolName.find(name) != std::string::npos) {
            searchResults.push_back(it.second);
        }
    }

    //sort data by school name
    std::sort(searchResults.begin(), searchResults.end(), [ ](DatabaseRecord const& record1, DatabaseRecord const& record2) {
        return record1.getSchoolName() < record2.getSchoolName();
    });

    if(searchResults.size() > 0) {
        found = true;
    } 
    else {
        found = false;
    }
    return searchResults;
}

/// @brief Search and return DatabaseRecord associated with provided DBN
/// @param dbn Unique key DBN
/// @param found Output parameter that represents if the search result was found
/// @return DatabaseRecord associated with dbn key
DatabaseRecord Database::searchByDbn(std::string dbn, bool& found) {
    std::transform(dbn.begin(), dbn.end(), dbn.begin(), [](unsigned char c){ return std::toupper(c); }); // convert dbn to upper
    auto result = this->records.find(dbn);
    if(result != this->records.end()) {
        found = true;
    }
    else {
        found = false;
    }
    return result->second;
}