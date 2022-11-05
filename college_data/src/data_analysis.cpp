#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "college_data/data_analysis.h"
#include "college_data/data_storage.h"

using namespace std;

namespace CollegeData
{
	unsigned int DataAnalysis::LevenshteinDistance(const std::string &s1, const std::string &s2)
	{
		////////////////////////
		// INIT - NOT MY CODE //
		////////////////////////
		// Reference: https://rosettacode.org/wiki/Levenshtein_distance#C++
		const unsigned int m(s1.size()), n(s2.size());

		if (m == 0) return n;
		if (n == 0) return m;

		unsigned int costs[n + 1];

		for (unsigned int k = 0; k <= n; k++) costs[k] = k;

		unsigned int i{ 0 };
		for (char const &c1 : s1)
		{
			costs[0] = i + 1;
			unsigned int corner{ i }, j{ 0 };
			for (char const &c2 : s2)
			{
				unsigned int upper{ costs[j + 1] };
				if (c1 == c2 || c1 == c2 + 32 || c2 == c1 + 32)// Modified here to look for upper and lower case similarity
					costs[j + 1] = corner;
				else
				{
					unsigned int t(upper < corner ? upper : corner);
					costs[j + 1] = (costs[j] < t ? costs[j] : t) + 1;
				}
				corner = upper;
				j++;
			}
			i++;
		}
		return costs[n];
		///////////////////////
		// END - NOT MY CODE //
		///////////////////////
	}

	unsigned int DataAnalysis::CheckEveryWordDistance(const std::string &s1, const std::string &s2)
	{
		int distance = 99;
		int aux = 0;
		int t1_pos_r = 0, t2_pos_r = 0;
		int t1_pos_l = 0, t2_pos_l = 0;
		while (t1_pos_r < s1.size())
		{
			t1_pos_r = s1.find(' ', t1_pos_l);
			if (t1_pos_r == string::npos || t1_pos_r > s1.size())
				t1_pos_r = s1.size();
			t2_pos_l = 0;
			t2_pos_r = 0;
			while (t2_pos_r < s2.size())
			{
				t2_pos_r = s2.find(' ', t2_pos_l);
				if (t2_pos_r == string::npos || t2_pos_r > s2.size())
					t2_pos_r = s2.size();
				aux = LevenshteinDistance(s1.substr(t1_pos_l, t1_pos_r - t1_pos_l), s2.substr(t2_pos_l, t2_pos_r - t2_pos_l));
				if (aux < distance)
					distance = aux;
				t2_pos_l = t2_pos_r + 1;
			}
			t1_pos_l = t1_pos_r + 1;
		}
		return distance;
	}

	std::stringstream &DataAnalysis::GetLastResult()
	{
		output.str("");
		sort(result_vector.begin(), result_vector.end(), [](School *a, School *b) { return (a->name.compare(b->name) < 0); });
		for (auto x : result_vector)
			output << *x << "\n";
		return output;
	}

	unsigned int DataAnalysis::SearchByName(std::string name, DataStorage &data_storage)
	{
		result_vector.clear();
		std::map<std::string, School *>school_map = data_storage.GetSchoolMap();
		for (auto x : school_map)
			if (CheckEveryWordDistance(x.second->name, name) < 3)
				result_vector.push_back(x.second);
		return result_vector.size();
	}

	unsigned int DataAnalysis::SearchByDbn(std::string dbn, DataStorage &data_storage)
	{
		result_vector.clear();
		std::map<std::string, School *>school_map = data_storage.GetSchoolMap();
		if (school_map.count(dbn))
			result_vector.push_back(school_map[dbn]);
		return result_vector.size();
	}
};// namespace CollegeData