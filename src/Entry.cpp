#include "../include/Entry.hpp"

Entry::Entry()
{
}

Entry::Entry(std::vector<std::string> entry)
{
    //! fill an Entry object using a CSV file row
    setDBN(entry[0]);
    setSchoolName(entry[1]);
    setNTestTakers(entry[2]);
    setCriticalReadingMean(entry[3]);
    setMathMean(entry[4]);
    setWritingMean(entry[5]);
}

std::string Entry::getDBN() const
{
    return this->dbn;
}

void Entry::setDBN(std::string newDBN)
{
    this->dbn = newDBN;
}

std::string Entry::getSchoolName() const
{
    return this->schoolName;
}

void Entry::setSchoolName(std::string newSchoolName)
{
    this->schoolName = newSchoolName;
}

std::string Entry::getNTestTakers() const
{
    return this->nTestTakers;
}

void Entry::setNTestTakers(std::string newNTestTakers)
{
    this->nTestTakers = newNTestTakers;
}

std::string Entry::getCriticalReadingMean() const
{
    return this->criticalReadingMean;
}

void Entry::setCriticalReadingMean(std::string newCriticalReadingMean)
{
    this->criticalReadingMean = newCriticalReadingMean;
}

std::string Entry::getMathMean() const
{
    return this->mathMean;
}

void Entry::setMathMean(std::string newMathMean)
{
    this->mathMean = newMathMean;
}

std::string Entry::getWritingMean() const
{
    return this->writingMean;
}

void Entry::setWritingMean(std::string newWritingMean)
{
    this->writingMean = newWritingMean;
}

void Entry::printEntry() const
{
    std::cout << "\nDBN = " << getDBN() << std::endl;
    std::cout << "School Name = " << getSchoolName() << std::endl;
    std::cout << "Number of Test Takers = " << getNTestTakers() << std::endl;
    std::cout << "Critical Reading Mean = " << getCriticalReadingMean() << std::endl;
    std::cout << "Mathematics Mean = " << getMathMean() << std::endl;
    std::cout << "Writing Mean = " << getWritingMean() << "\n"
              << std::endl;
}

bool Entry::empty()
{
    //! DBN is obligatory to every entry
    return getDBN().empty();
}

void Entry::printEntryInCSV(std::ofstream& csvFile) const
{
    csvFile << getDBN() << "," << getSchoolName() << "," << getNTestTakers() << "," << getCriticalReadingMean() << "," << getMathMean() << "," << getWritingMean() << "\n";
}
