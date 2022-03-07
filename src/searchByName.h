/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/searchByName.h
 **/

#include <string>
#include <vector>

namespace CppChallenge {
namespace SearchByName {

class searchByName {
public:
    searchByName();
    ~searchByName();

    std::vector<std::vector<std::string>> FindName(
            const std::vector<std::vector<std::string>> &data, std::string name) const;
};

} // namespace SearchByName
} // namespace CppChallenge
