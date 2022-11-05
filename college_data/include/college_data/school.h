#pragma once

#include <string>
#include <iostream>

namespace CollegeData
{
	struct School
	{
		std::string dbn = "";
		std::string name = "";
		unsigned int num_test_takers = 0;
		int critical_reading_mean = 0;
		int mathematic_mean = 0;
		int writing_mean = 0;
		friend std::ostream &operator<<(std::ostream &os, const School &obj)
		{
			return os << obj.dbn
					  << "," << obj.name
					  << "," << obj.num_test_takers
					  << "," << obj.critical_reading_mean
					  << "," << obj.mathematic_mean
					  << "," << obj.writing_mean;
		}
	};
};// namespace CollegeData
