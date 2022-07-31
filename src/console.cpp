/**
 * @file console.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "console.h"

void Console::printOperationsMenu(){
    std::cout << std::endl;
    std::cout << "Please, select an operation by entering its number:" << std::endl;
    std::cout << "    [1] Search college by its DBN" << std::endl;
    std::cout << "    [2] Search college by its school name" << std::endl;
    std::cout << "    [3] Exit" << std::endl;
}

Operation Console::getUserOperation(){
    char operation;
    std::cout << "Operation: ";
    std::cin >> operation;
    
    if(operation == '1'){
        return Operation::SearchDBN;
    } else if(operation == '2'){
        return Operation::SearchSchoolName;
    } else if(operation == '3'){
        return Operation::Exit;
    } else {
        std::cout << "Invalid operation" << std::endl;
        return Operation::None;
    }
}

std::string Console::getUserSearch(){
    std::string search;
    std::cout << "Type your search: ";
    std::cin >> search;
    return search;
}

bool Console::getUserFilePreference(){
    char preference;
    std::cout << "Save the search result to file? [y/n] ";
    std::cin >> preference;
    return preference == 'y';
}

void Console::printSearchResult(const std::ostringstream& stream){
    std::cout << std::endl;
    std::cout << stream.str();
}