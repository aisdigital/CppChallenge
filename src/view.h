/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/view.h
 **/

#include <string>
#include <vector>

namespace CppChallenge {
namespace View {

class view {
public:
    view();
    ~view();

    uint ReadInt() const;
    std::string ReadString() const;
    uint ReadYesNoConfirmation() const;

    void InfoInit();
    void InfoNoDataCloseProgram();
    void InfoLoadData();
    void InfoReturnToMainMenu();
    void InfoFileNotSaved();
    void InfoInvalidAnswer();
    void InfoFileSaved();
    void InfoErrorSavingFile();
    void InfoResult();
    void InfoNameNotFound();
    void InfoDbnNotFound();
    void InfoEndProgram();
    void InfoInvalidOption();

    void MainMenu();
    void MenuSearchByName();
    void MenuAskSaveFile();
    void MenuSaveFile();
    void MenuSearchByDbn();

    void PrintResults(const std::vector<std::string> &header,
                      const std::vector<std::vector<std::string>> &results_list);

private:
    void PrintHeader(const std::vector<std::string> &header);
    void PrintLine(const std::string &print_string);
    void PrintLine() const;
    void Print(const std::string &print_string) const;
};

}  // namespace View
}  // namespace CppChallenge