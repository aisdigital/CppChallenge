#ifndef SCHOOL_DATA_HPP
#define SCHOOL_DATA_HPP

#include <string>

class SchoolData
{
  public:
    SchoolData() = default;

    SchoolData(
      const std::string& _dbn,
      const std::string& _schoolName,
      const std::string& _numberOfTestTakers,
      const std::string& _criticalReadingMean,
      const std::string& _mathematicsMean,
      const std::string& _writingMean
    );

    SchoolData(
      const SchoolData& other
    );

    virtual ~SchoolData() = default;

    bool operator<(
      const SchoolData& other
    );

    bool operator>(
      const SchoolData& other
    );

    std::string ToString() const;

    const std::string& DBN() const;

    const std::string& SchoolName() const;

    const std::string& NumberOfTestTakers() const;

    const std::string& CriticalReadingMean() const;

    const std::string& MathematicsMean() const;

    const std::string& WritingMean() const;

  private:
    std::string dbn;
    std::string schoolName;
    std::string numberOfTestTakers;
    std::string criticalReadingMean;
    std::string mathematicsMean;
    std::string writingMean;
};

#endif