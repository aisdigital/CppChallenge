#ifndef DATABASE_RECORD_HPP
#define DATABASE_RECORD_HPP

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
    DatabaseRecord();
    ~DatabaseRecord();

    std::string getDbn() const;
    std::string getSchoolName() const;
    std::string getTestTakers() const;
    std::string getCriticalReadingMean() const;
    std::string getMathMean() const;
    std::string getWritingMean() const;

private:
    std::string dbn;
    std::string schoolName;
    std::string testTakers;
    std::string criticalReadingMean;
    std::string mathMean;
    std::string writingMean;
};

#endif