#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace FileUtils {
std::vector<std::string> ReadCSV(const std::string &filename) {
  std::vector<std::string> buffer;

  std::ifstream inputFile;
  inputFile.open(filename.c_str());

  if (inputFile.is_open()) {
    std::string line;

    while (std::getline(inputFile, line)) {
      buffer.push_back(line);
    }

    inputFile.close();
  }

  return buffer;
}
}; // namespace FileUtils
