#pragma once

#include <string>

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
	};
};// namespace CollegeData