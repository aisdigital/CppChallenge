/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/core.h
 **/

#include <memory>
#include <string>
#include <vector>

namespace CppChallenge {

namespace FileRead {
class fileRead;
}  // namespace FileRead

namespace View {
class view;
}  // namespace View

}  // namespace CppChallenge

namespace CppChallenge {
namespace Core {

class core {
public:
    core();
    ~core();

private:
    void Init();
    bool LoadData();
    void Loop();

    void MainMenu();
    void MainMenuInput();
    void MenuSearchByName();
    void DisplayResultsByName();
    void MenuAskSaveFile();
    void MenuSaveFile();
    void MenuSearchByDbn();
    void DisplayResultsByDbn();
    void EndProgram();
    void InvalidOption();

    std::vector<std::vector<std::string>> data_;
    std::vector<std::string> data_header_;
    std::vector<std::vector<std::string>> search_result_;
    std::string file_path_;
    bool end_program_;
    View::view *view_;
    FileRead::fileRead *file_reader_;
};

}  // namespace Core
}  // namespace CppChallenge