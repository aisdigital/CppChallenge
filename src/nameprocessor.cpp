

#include "../include/nameprocessor.h"

const std::vector<std::pair<std::string, std::string> > NameProcessor::ACRONYM_LIST = {
    {"HS", "HIGH SCHOOL"},
    {"NYC", "NEW YORK CITY"},
    {"@", "AT"},
    {"&", "AND"}
};

const std::vector<std::string> NameProcessor::SYMBOLS_LIST = {
    "\"",
    "\'",
    "!",
    "?"
};

NameProcessor::NameProcessor()
{

}

std::string NameProcessor::processShoolName(const std::string& name)
{
    std::string treatedName(name);
    
    removeSymbols(treatedName);
    capitalizeLetters(treatedName);
//    expandAcronyms(treatedName);

    return treatedName;
}

bool NameProcessor::hasSubString(const std::string &processedName, const std::string &substring)
{
    bool ret =  (processedName.find(processShoolName(substring)) != std::string::npos);
    return ret;
}

void NameProcessor::capitalizeLetters(std::string& letters)
{
    for (auto& letter : letters) {
        letter = std::toupper(letter);
    }
}

void NameProcessor::expandAcronyms(std::string& name)
{
     static const std::string space = " ";
    
     unsigned posStart = 0;

    while (true) {
        auto posFound = name.find(space, posStart);
        if (posFound == std::string::npos) {
            break;
        } else {
            auto word = name.substr(posStart, posFound - posStart);
            for (const auto& acronym : ACRONYM_LIST) {
                if (!acronym.first.compare(word)) {
                    name.replace(posStart, posFound - posStart, acronym.second);
                    break;
                }
            }
            posStart += word.length() + space.length();
        }
    }
}

void NameProcessor::removeSymbols(std::string &name)
{
    for (const auto& symbol : SYMBOLS_LIST) {
        unsigned posStart = 0;
        while (true) {
            auto posFound = name.find(symbol, posStart);
            if (posFound == std::string::npos) {
                break;
            } else {
                name.erase(posFound, symbol.length());
                posStart += posFound + symbol.length();
            }
        }
    }
}
