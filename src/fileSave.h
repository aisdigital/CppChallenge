/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/fileSave.h
 **/

#include <string>
#include <vector>

namespace CppChallenge {
namespace FileSave {

class fileSave {
public:
    fileSave();
    ~fileSave();

    bool SaveFile(const std::vector<std::vector<std::string>> &data,
                  const std::vector<std::string> &header,
                  std::string path) const;

private:
    void WriteHeader(const std::vector<std::string> &header, std::ofstream &file) const;
};

}  // namespace FileSave
}  // namespace CppChallenge
