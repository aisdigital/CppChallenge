/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/searchByName.cpp
 **/

#include <string>

#include "searchByName.h"

namespace CppChallenge {
namespace SearchByName {
    
searchByName::searchByName() {
}

searchByName::~searchByName() {}

std::vector<std::vector<std::string>> searchByName::FindName(
        const std::vector<std::vector<std::string>> &data, std::string name) const {
    std::vector<std::vector<std::string>> output_list;
    for (int i = 1; i < data.size(); i++) {
        std::string current_line_name(data[i][1]);
        if (current_line_name.find(name) != std::string::npos) {
            output_list.push_back(data[i]);
        }
    }
    return output_list;
}

}  // namespace SearchByName
}  // namespace CppChallengename
