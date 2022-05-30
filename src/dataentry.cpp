

#include "../include/dataentry.h"

#include <stdexcept>

#include "../include/nameprocessor.h"

DataEntry::DataEntry() :
    m_state(DataEntryState::Empty),
    m_valueDBN(""),
    m_school(""),
    m_testTakers(0),
    m_readingMean(0),
    m_mathMean(0),
    m_writingMean(0),
    m_treatedName("")
{
}

std::string DataEntry::getDBN() const
{
    return m_valueDBN;
}

std::string DataEntry::getSchoolName() const
{
    return m_school;
}

bool DataEntry::isFull() const
{
    return (m_state == DataEntry::DataEntryState::Full);
}

float DataEntry::getTestTakers() const
{
    return m_testTakers;
}

std::string DataEntry::getTreatedName() const
{
    return m_treatedName;
}

void DataEntry::setAttribute(DataAttribute attribute, const std::string &value)
{
    auto treatNumbers =
            [](const std::string& possibleNumValue) -> unsigned
    {
        unsigned num_value = 0;
        try {
            num_value = static_cast<unsigned>(std::stof(possibleNumValue));
        } catch(std::invalid_argument&) {
            ;
        }

        return num_value;
    };
    auto treatSchoolName =
            [](const std::string& name) -> std::string
    {
        NameProcessor processor;
        return processor.processShoolName(name);
    };

    // Change Entry Attribute
    switch (attribute) {
    case DataAttribute::DBNValue:
        m_valueDBN = value;
        break;
    case DataAttribute::SchoolName:
        m_school = value;
        m_treatedName = treatSchoolName(value);
        break;
    case DataAttribute::TestTakers:
        m_testTakers = treatNumbers(value);
        break;
    case DataAttribute::MathMean:
        m_mathMean = treatNumbers(value);
        break;
    case DataAttribute::WritingMean:
        m_writingMean = treatNumbers(value);
        break;
    case DataAttribute::ReadingMean:
        m_readingMean = treatNumbers(value);
        break;
    default:
        break;
    }

    // Change Entry State
    switch (m_state) {
    case DataEntryState::Full:
        if (m_valueDBN == "") {
            m_state = DataEntryState::Empty;
        } else if (m_testTakers == 0) {
            m_state = DataEntryState::Partial;
        }
        break;
    case DataEntryState::Partial:
        if (m_valueDBN == "") {
            m_state = DataEntryState::Empty;
        } else if (m_testTakers != 0) {
            m_state = DataEntryState::Full;
        }
        break;
    case DataEntryState::Empty:
    default:
        if (m_valueDBN != "" && m_school != "" && m_testTakers != 0) {
            m_state = DataEntryState::Full;
        } else if (m_valueDBN != "" && m_school != "") {
            m_state = DataEntryState::Partial;
        }
        break;
    }
}

DataAttribute convertStrToDataAttribute(const std::string &attribute)
{
    DataAttribute ret = DataAttribute::NotFound;
    if (attribute == "DBN") {
        ret = DataAttribute::DBNValue;
    } else if (attribute == "School Name") {
        ret = DataAttribute::SchoolName;
    } else if (attribute == "Number of Test Takers") {
        ret = DataAttribute::TestTakers;
    } else if (attribute == "Critical Reading Mean") {
        ret = DataAttribute::ReadingMean;
    } else if (attribute == "Mathematics Mean") {
        ret = DataAttribute::MathMean;
    } else if (attribute == "Writing Mean") {
        ret = DataAttribute::WritingMean;
    }
    return ret;
}

std::string convertDataAttributeToString(DataAttribute attribute)
{
    std::string ret = "";
    switch (attribute) {
    case DataAttribute::DBNValue:
        ret = "DBN";
        break;
    case DataAttribute::SchoolName:
        ret = "School Name";
        break;

    case DataAttribute::TestTakers:
        ret = "Number of Test Takers";
        break;
    case DataAttribute::MathMean:
        ret = "Mathematics Mean";
        break;
    case DataAttribute::WritingMean:
        ret = "Writing Mean";
        break;
    case DataAttribute::ReadingMean:
        ret = "Critical Reading Mean";
        break;
    default:
        break;
    }
    return ret;
}

std::ostream &operator<<(std::ostream& output, const DataEntry& entry)
{

    output << entry.m_valueDBN << ",";
    output << entry.m_school << ",";
    if (entry.m_state != DataEntry::DataEntryState::Full) {
        output << ",,,";
    } else {
        output << entry.m_testTakers << ",";
        output << entry.m_readingMean << ",";
        output << entry.m_mathMean << ",";
        output << entry.m_writingMean;
    }
    return output;
}

std::istream &operator>>(std::istream& input, DataEntry& entry)
{
    input >> entry.m_valueDBN;
    input >> entry.m_school;
    input >> entry.m_testTakers;
    input >> entry.m_readingMean;
    input >> entry.m_mathMean;
    input >> entry.m_writingMean;
    return input;
}
