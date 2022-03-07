/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/searchByDbn.cpp
 **/

#include "searchByDbn.h"

#include <sstream>

namespace CppChallenge {
namespace SearchByDbn {

searchByDbn::searchByDbn() {
}

searchByDbn::~searchByDbn() {}

std::vector<std::string> searchByDbn::FindDbn(
            const std::vector<std::vector<std::string>> &data, std::string dbn) const {
    for (int i = 1; i < data.size(); i++) {
        std::stringstream current_line_dbn(data[i][0]);
        std::string single_dbn;
        std::vector<std::string> dbn_list;
        while(std::getline(current_line_dbn, single_dbn, '/')) {
            dbn_list.push_back(single_dbn);
        }
        for (int j = 0; j < dbn_list.size(); j++) {
            if (dbn_list[j].compare(dbn) == 0) {
                return data[i];
            }
        }
    }
    return {};
}
 
}  // namespace SearchByDbn
}  // namespace CppChallenge
