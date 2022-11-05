#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "school.h"
#include "data_classes.h"

namespace CollegeData
{
	class DataAnalysis
	{
	  private:
		std::vector<School *> result_vector;
		std::stringstream output;

		unsigned int LevenshteinDistance(const std::string &s1, const std::string &s2);
		unsigned int CheckEveryWordDistance(const std::string &s1, const std::string &s2);

	  protected:
	  public:
		DataAnalysis() {}
		~DataAnalysis() {}

		std::stringstream &GetLastResult();
		unsigned int SearchByName(std::string name, DataStorage &data_storage);
		unsigned int SearchByDbn(std::string dbn, DataStorage &data_storage);
	};
};// namespace CollegeData