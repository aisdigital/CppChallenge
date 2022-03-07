/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/fileRead.cpp
 **/

#include <fstream>
#include <iostream>
#include <sstream>

#include "fileRead.h"
 
namespace CppChallenge {
namespace FileRead {


fileRead::fileRead() {
}

fileRead::~fileRead() {}

std::vector<std::vector<std::string>> fileRead::ReadFile(const std::string &file_path) const {
    std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
	std::string line;
    std::string word;
 
	std::fstream file (file_path, std::ios::in);
	if(file.is_open()) {
		while(getline(file, line)) {
			row.clear();
 			std::stringstream str(line);
 			while(std::getline(str, word, ',')) {
				row.push_back(word);
            }
			data.push_back(row);
		}
	}
 	return data;
}

}  // namespace FileRead
}  // namespace CppChallenge