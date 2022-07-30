/**
 * @file csv_file.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "csv_file.h"

CSVFile::CSVFile(const std::string& path){
    open(path);
}

bool CSVFile::open(const std::string& path){
    std::ifstream file(path);
    m_data.clear();

    if(file.is_open()){
        while(file.good()){
            std::string line;
            std::getline(file, line);
            if(!line.empty()){
                loadLine(line);
            }
        }
        file.close();
        return true;
    }

    return false;
}

size_t CSVFile::rows(){
    return m_data.size();
}

size_t CSVFile::cols(){
    if(m_data.empty()){
        return 0;
    } else {
        return m_data[0].size();
    }
}

std::vector<std::vector<std::string>> CSVFile::data(){
    return m_data;
}

void CSVFile::loadLine(const std::string& line){
    std::vector<std::string> row;
    size_t start, end, index = 0;

    while(index < line.size()){
        if(line[index] == COMMA) {
            start = index + 1;
            if(line[start] == QUOTE){
                end = line.find(QUOTE, start + 1);
            } else {
                end = line.find(COMMA, index + 1) - 1;
            }
        } else {
            start = index;
            end = line.find(COMMA, index + 1) - 1;
        }
        std::string cell = line.substr(start, end - start + 1);
        row.push_back(cell);
        index = end + 1;
    }
    
    m_data.push_back(row);
}