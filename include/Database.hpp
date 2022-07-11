
#include "FileUtils.hpp"
#include "Parser.hpp"
#include "SchoolSatResult.h"

#include <algorithm>

class Database {
public:
  void Read(const std::string &filename) {
    std::vector<std::string> buffer = FileUtils::ReadCSV(filename);
    schoolSatResultData = Parser::ToSchoolSatList(buffer);
  }

  SchoolSatResult FindByDBN(const std::string &DBN) {
    return schoolSatResultData.at(DBN);
  }

  SchoolSatResult FindBySchoolName(const std::string &schoolName) {
    auto is_sameSchoolName =
        [&schoolName](const std::pair<std::string, SchoolSatResult> &item) {
          return (item.second.SchoolName == schoolName);
        };

    auto result =
        std::find_if(std::begin(schoolSatResultData),
                     std::end(schoolSatResultData), is_sameSchoolName);

    if (result != std::end(schoolSatResultData)) {
      return result->second;
    }

    SchoolSatResult schoolSatResultFound;
    return schoolSatResultFound;
  }

private:
  std::unordered_map<std::string, SchoolSatResult> schoolSatResultData;
};
