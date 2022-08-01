#ifndef SCHOOL_DATA_MAP_HPP
#define SCHOOL_DATA_MAP_HPP

#include <map>
#include <string>
#include <vector>

#include "csv.h"
#include "SchoolData.hpp"

class SchoolDataMap
{
  public:
    SchoolDataMap() = default;

    virtual ~SchoolDataMap() = default;

    bool Load(
      const std::string& inputPath
    );

    bool Save(
      const std::string& fileName,
      const std::vector<std::shared_ptr<SchoolData>>& schoolsData
    ) const;

    std::vector<std::shared_ptr<SchoolData>> SeachBySchoolName(
      const std::string& schoolName
    );

    std::vector<std::shared_ptr<SchoolData>> SeachBySchoolDBN(
      const std::string& schoolDBN
    );

    void CreateOutputFolder() const;

  private:
    const std::string outputPath = "./output/";
    std::map<std::string, std::shared_ptr<SchoolData>> schoolDataMap;
};

#endif