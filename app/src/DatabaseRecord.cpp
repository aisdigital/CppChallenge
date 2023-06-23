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

DatabaseRecord::~DatabaseRecord() {}

std::string DatabaseRecord::getDbn() {
    return this->dbn;
}

std::string DatabaseRecord::getSchoolName() {
    return this->schoolName;
}

std::string DatabaseRecord::getTestTakers() {
    return this->testTakers;
}

std::string DatabaseRecord::getCriticalReadingMean() {
    return this->criticalReadingMean;
}

std::string DatabaseRecord::getMathMean() {
    return this->mathMean;
}

std::string DatabaseRecord::getWritingMean() {
    return this->writingMean;
}