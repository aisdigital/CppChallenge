
#include <iostream>
#include <string>

enum class DataAttribute
{
    NotFound = 0,
    DBNValue,
    SchoolName,
    TestTakers,
    ReadingMean,
    MathMean,
    WritingMean,
};

DataAttribute convertStrToDataAttribute(const std::string& attribute);

std::string convertDataAttributeToString(DataAttribute attribute);

class DataEntry
{
    enum class DataEntryState
    {
        Empty = 0,
        Partial,
        Full
    };

    DataEntryState m_state;

    std::string m_valueDBN;

    std::string m_school;

    int m_testTakers;

    float m_readingMean;

    float m_mathMean;

    float m_writingMean;

    std::string m_treatedName;

public:
    DataEntry();

    std::string getDBN() const;

    std::string getSchoolName() const;

    bool isFull() const;

    float getTestTakers() const;

    std::string getTreatedName() const;

    void setAttribute(DataAttribute attribute, const std::string& value);

    friend std::ostream &operator<<(std::ostream& output, const DataEntry& entry);

    friend std::istream &operator>>(std::istream& input, DataEntry& entry);
};
