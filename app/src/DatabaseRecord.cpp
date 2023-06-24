#include "DatabaseRecord.hpp"

DatabaseRecord::DatabaseRecord(std::string dbn, std::string schoolName, std::string testTakers, 
    std::string criticalReadingMean, std::string mathMean, std::string writingMean) :
    dbn(dbn),
    schoolName(schoolName),
    testTakers(testTakers),
    criticalReadingMean(criticalReadingMean),
    mathMean(mathMean),
    writingMean(writingMean)
{}

DatabaseRecord::DatabaseRecord() :
    dbn(""),
    schoolName(""),
    testTakers(""),
    criticalReadingMean(""),
    mathMean(""),
    writingMean("") 
{}

DatabaseRecord::~DatabaseRecord() {}

std::string DatabaseRecord::getDbn() const {
    return this->dbn;
}

std::string DatabaseRecord::getSchoolName() const {
    return this->schoolName;
}

std::string DatabaseRecord::getTestTakers() const {
    return this->testTakers;
}

std::string DatabaseRecord::getCriticalReadingMean() const {
    return this->criticalReadingMean;
}

std::string DatabaseRecord::getMathMean() const {
    return this->mathMean;
}

std::string DatabaseRecord::getWritingMean() const {
    return this->writingMean;
}