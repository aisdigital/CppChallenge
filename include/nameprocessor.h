

#include <string>
#include <utility>
#include <vector>

class NameProcessor
{

public:
    static const std::vector< std::pair<std::string, std::string> > ACRONYM_LIST;

    static const std::vector<std::string> SYMBOLS_LIST;

    NameProcessor();

    void capitalizeLetters(std::string& letters);

    void expandAcronyms(std::string& name);

    void removeSymbols(std::string& name);

    std::string processShoolName(const std::string& originalName);

    bool hasSubString(const std::string& processedName, const std::string& substring);
};
