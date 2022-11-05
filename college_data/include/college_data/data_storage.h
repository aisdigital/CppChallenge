#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "school.h"
#include "data_classes.h"

namespace CollegeData
{
	class DataStorage
	{
	  private:
		std::map<std::string, School *> school_map;

		void TokenizeSchoolData(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> &t_pos_vector);
		int IsSchoolDataValid(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> const &t_pos_vector);
		void AddSchool(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> const &t_pos_vector);

	  protected:
		friend class DataAnalysis;
		std::map<std::string, School *> const &GetSchoolMap(); // Map with duplicated DBN info.. (key and inside school structure)

	  public:
		DataStorage() {}
		~DataStorage() {}

		void AddDataFromCsv(std::istream &csv_data);
		unsigned int GetNumberOfAddedSchools();
	};
};// namespace CollegeData