#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//! A class representation of an entry in the CSV file.
class Entry
{
private:
    //! class members
    std::string dbn;
    std::string schoolName;
    std::string nTestTakers;
    std::string criticalReadingMean;
    std::string mathMean;
    std::string writingMean;

public:
    //! constructors
    Entry();
    Entry(std::vector<std::string> entry);

    //! getters and setters for the class members
    std::string getDBN() const;
    void setDBN(std::string newDBN);

    std::string getSchoolName() const;
    void setSchoolName(std::string newSchoolName);

    std::string getNTestTakers() const;
    void setNTestTakers(std::string newNTestTakers);

    std::string getCriticalReadingMean() const;
    void setCriticalReadingMean(std::string newCriticalReadingMean);

    std::string getMathMean() const;
    void setMathMean(std::string newMathMean);

    std::string getWritingMean() const;
    void setWritingMean(std::string newWritingMean);

    //! print entry object
    void printEntry() const;
    //! check if the object is empty
    bool empty();
    //! print object in .csv format
    void printEntryInCSV(std::ofstream& csvFile) const;
};