/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/fileSave.cpp
 **/

#include "fileSave.h"

#include <fstream>
#include <iostream>

namespace CppChallenge {
namespace FileSave {

fileSave::fileSave() {
}

fileSave::~fileSave() {}

bool fileSave::SaveFile(const std::vector<std::vector<std::string>> &data,
                        const std::vector<std::string> &header,
                        std::string path) const {
    std::ofstream file;
    file.open(path);
    WriteHeader(header, file);
    for (int i = 0; i < data.size(); i++) {                                                     // TODO: Add header
        for (int j = 0; j < data[i].size(); j++) {
            if (j) {
                file << ",";
            }
            file << data[i][j];
        }
        file << "\n";
    }
    file.close();
    return !file.fail();
}

void fileSave::WriteHeader(const std::vector<std::string> &header, std::ofstream &file) const {
    for (int k = 0; k < header.size(); k++) {
        if (k) {
            file << ",";
        }
        file << header[k];
    }
    file << "\n";
}

}  // namespace FileSave
}  // namespace CppChallenge
