/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/fileRead.h
 **/

#include <vector>
#include <string>

namespace CppChallenge {
namespace FileRead {

class fileRead {
public:
    fileRead();
    ~fileRead();

    std::vector<std::vector<std::string>> ReadFile(const std::string &file_path) const;
private:
};

}  // namespace FileRead
}  // namespace CppChallenge