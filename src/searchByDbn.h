/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/searchByDbn.h
 **/

#include <string>
#include <vector>

namespace CppChallenge {
namespace SearchByDbn {

class searchByDbn {
public:
    searchByDbn();
    ~searchByDbn();

    std::vector<std::string> FindDbn(const std::vector<std::vector<std::string>> &data, std::string dbn) const;
};

} // namespace SearchByDbn
} // namespace CppChalleng {
