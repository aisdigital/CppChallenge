#pragma once

#include <regex>
#include <sstream>
#include <unordered_map>

#include "SchoolSatResult.h"

namespace Parser {
/**
 * Convert SchoolSatResult to the CSV String with the following format
 * "{DBN},{SchoolName},{TestTakersNumber},{CriticalReadingMean},{MathematicsMean},{WritingMean}"
 */
static std::string ToString(const SchoolSatResult &schoolSatResult) {
  std::ostringstream ss;

  // Identification: {DBN},{SchoolName}
  ss << schoolSatResult.DBN << "," << schoolSatResult.SchoolName << ",";

  if (schoolSatResult.TestTakesNumber != 0) {
    ss << schoolSatResult.TestTakesNumber;
  }

  ss << ",";

  // {CriticalReadingMean}
  if (schoolSatResult.CriticalReadingMean != 0) {
    ss << schoolSatResult.CriticalReadingMean;
  }

  ss << ",";

  // {MathematicsMean}
  if (schoolSatResult.MathematicsMean != 0) {
    ss << schoolSatResult.MathematicsMean;
  }

  ss << ",";

  // {WritingMean}
  if (schoolSatResult.WritingMean != 0) {
    ss << schoolSatResult.WritingMean;
  }

  return ss.str();
}

/**
 * Convert A CSV String with the format bellow to SchoolSatResult
 * "{DBN},{SchoolName},{TestTakersNumber},{CriticalReadingMean},{MathematicsMean},{WritingMean}"
 */
static SchoolSatResult ToSchoolSatResult(const std::string &csvString) {
  const std::regex schoolSatResultRegex(
      "([0-9A-Z]*),([a-zA-Z0-9 ]*),([0-9]*),([0-9]*),([0-9]*),([0-9]*)");
  std::smatch filterResult;

  SchoolSatResult schoolSatResult;

  if (std::regex_search(csvString, filterResult, schoolSatResultRegex)) {
    schoolSatResult.DBN = filterResult[1];
    schoolSatResult.SchoolName = filterResult[2];

    try {
      schoolSatResult.TestTakesNumber = std::stoul(filterResult[3]);
      schoolSatResult.CriticalReadingMean = std::stoul(filterResult[4]);
      schoolSatResult.MathematicsMean = std::stoul(filterResult[5]);
      schoolSatResult.WritingMean = std::stoul(filterResult[6]);
    } catch (...) {
      schoolSatResult.TestTakesNumber = 0;
      schoolSatResult.CriticalReadingMean = 0;
      schoolSatResult.MathematicsMean = 0;
      schoolSatResult.WritingMean = 0;
    }
  }

  return schoolSatResult;
}

static std::unordered_map<std::string, SchoolSatResult>
ToSchoolSatList(std::vector<std::string> &csvStringList) {
  std::unordered_map<std::string, SchoolSatResult> schoolSatResultList;

  for (std::vector<std::string>::iterator it = std::begin(csvStringList);
       it != std::end(csvStringList); ++it) {
    SchoolSatResult schoolSatResult = ToSchoolSatResult(*it);
    schoolSatResultList.insert(
        std::make_pair(schoolSatResult.DBN, schoolSatResult));
  }

  return schoolSatResultList;
}
}; // namespace Parser
