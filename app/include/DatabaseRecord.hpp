#include <string>

/*
DatabaseRecord.hpp: provides a representation of one entry of database records
Author: Lucca Leão
Date: 23/06/2023
*/

class DatabaseRecord {
public:
    DatabaseRecord(std::string dbn, std::string schoolName, std::string testTakers, 
        std::string criticalReadingMean, std::string mathMean, std::string writingMean);
    ~DatabaseRecord();

    std::string getDbn();
    std::string getSchoolName();
    std::string getTestTakers();
    std::string getCriticalReadingMean();
    std::string getMathMean();
    std::string getWritingMean();

private:
    std::string dbn;
    std::string schoolName;
    std::string testTakers;
    std::string criticalReadingMean;
    std::string mathMean;
    std::string writingMean;
};