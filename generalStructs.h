#ifndef GENERAL_STRUCSTS_H
#define GENERAL_STRUCSTS_H

#include <string>
#include <iostream>
#include <iomanip>


struct SATModel_st
{
    std::string DBN;
    std::string school_name;
    std::string n_of_test_takers;
    std::string critical_read_mean;
    std::string mathematics_mean;
    std::string writing_mean;
};


enum class columnsOfSATFile 
{
    DBN = 1,
    SCHOOL_NAME = 2,
    N_OF_TEST_TAKERS = 3,
    CRITICAL_READING_MEAN = 4,
    MATHEMATICS_MEAN = 5,
    WRITING_MEAN = 6
};


enum class ExcelModelType_en
{
    Generic = 0,
    SATModel = 1
};

inline std::ostream &operator<<(std::ostream &out , const SATModel_st &dataToOutput)
{
  out << "===============================================================" << std::endl;
  out << std::setw(15) << std::left << "DBN: " << dataToOutput.DBN << std::endl;
  out << std::setw(15) << std::left << "School Name: " << dataToOutput.school_name << std::endl;
  out << std::setw(15) << std::left << "Test Takers: " << dataToOutput.n_of_test_takers << std::endl;
  out << std::setw(15) << std::left << "Read Mean: " << dataToOutput.critical_read_mean << std::endl;
  out << std::setw(15) << std::left << "Math Mean: " << dataToOutput.mathematics_mean << std::endl;
  out << std::setw(15) << std::left <<"Writing Mean: " << dataToOutput.writing_mean << std::endl;
  out << "===============================================================" << std::endl;
  return out;
}

#endif