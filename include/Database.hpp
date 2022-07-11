
#include "FileUtils.hpp"
#include "Parser.hpp"
#include "SchoolSatResult.h"

#include <algorithm>

class Database {
public:
  void Read(const std::string &filename) {
    std::vector<std::string> buffer = FileUtils::Read(filename);
    schoolSatResultData = Parser::ToSchoolSatList(buffer);
  }

  SchoolSatResult FindByDBN(const std::string &DBN) {
    return schoolSatResultData.at(DBN);
  }

  std::vector<SchoolSatResult> FindBySchoolName(const std::string &schoolName) {
    std::vector<SchoolSatResult> searchResultList;

    auto addIfSimilarSchoolName =
        [&schoolName, &searchResultList](
            const std::pair<std::string, SchoolSatResult> &item) {
          if (item.second.SchoolName.find(schoolName) != std::string::npos) {
            searchResultList.push_back(item.second);
          }
        };

    std::for_each(std::begin(schoolSatResultData),
                  std::end(schoolSatResultData), addIfSimilarSchoolName);

    auto isSchoolNameOrdered = [](const SchoolSatResult &schoolA,
                                  const SchoolSatResult &schoolB) -> bool {
      return (schoolA.SchoolName < schoolB.SchoolName);
    };

    std::sort(std::begin(searchResultList), std::end(searchResultList),
              isSchoolNameOrdered);

    return searchResultList;
  }

private:
  std::unordered_map<std::string, SchoolSatResult> schoolSatResultData;
};
