/**
 * @file csv_file.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define QUOTE '"'
#define COMMA ','

/**
 * @brief 
 * 
 */
class CSVFile {
    public:

    CSVFile() = default;
    CSVFile(const std::string& path);
    bool open(const std::string& path);
    size_t rows();
    size_t cols();
    std::vector<std::vector<std::string>> data();

    private:

    void loadLine(const std::string& row);

    std::vector<std::vector<std::string>> m_data;
};

#endif