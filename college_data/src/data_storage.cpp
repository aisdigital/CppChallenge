#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "college_data/data_storage.h"

using namespace std;

namespace CollegeData
{
	void DataStorage::TokenizeSchoolData(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> &v_t_pos)
	{
		unsigned int t_count = 0;
		unsigned int t_pos_r = 0;
		unsigned int t_pos_l = 0;
		int size = school_info.size();
		v_t_pos.clear();
		while (t_pos_r < size)
		{
			if (school_info[t_pos_r + 1] == '\"')
			{
				t_pos_l = t_pos_r + 2;
				t_pos_r = school_info.find('\"', t_pos_l + 1);
				if (t_pos_r == string::npos || t_pos_r > size)
					return;
				v_t_pos.push_back(tuple<unsigned int, unsigned int>(t_pos_l, t_pos_r));
				t_pos_l = t_pos_r + 2;
			}
			else
			{
				t_pos_r = school_info.find(',', t_pos_l);
				if (t_pos_r == string::npos || t_pos_r > size)
					t_pos_r = size;
				v_t_pos.push_back(tuple<unsigned int, unsigned int>(t_pos_l, t_pos_r));
				t_pos_l = t_pos_r + 1;
			}
		}
	}

	int DataStorage::IsSchoolDataValid(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> const &v_t_pos)
	{
		return v_t_pos.size() == 6;// Should be improved..
	}

	void DataStorage::AddSchool(std::string const &school_info, std::vector<std::tuple<unsigned int, unsigned int>> const &v_t_pos)
	{
		School *school = new School();
		string s_aux;
		int i = 0;

		auto get_element_from_school_info = [school_info, v_t_pos](int i) {
			return school_info.substr(get<0>(v_t_pos[i]), get<1>(v_t_pos[i]) - get<0>(v_t_pos[i]));
		};

		school->dbn = get_element_from_school_info(i++);

		school->name = get_element_from_school_info(i++);

		s_aux = get_element_from_school_info(i++);
		school->num_test_takers = (s_aux == "") ? 0 : stoi(s_aux);// Check for valid number data, could improve here

		s_aux = get_element_from_school_info(i++);
		school->critical_reading_mean = (s_aux == "") ? 0 : stoi(s_aux);

		s_aux = get_element_from_school_info(i++);
		school->mathematic_mean = (s_aux == "") ? 0 : stoi(s_aux);

		s_aux = get_element_from_school_info(i++);
		school->writing_mean = (s_aux == "") ? 0 : stoi(s_aux);

		if (school_map.count(school->dbn))
		{// The README says the DBN are unique
		 // Here duplicated DBN keys are ignored.. could have prompt the user to choose or something else..
		 // Informative cout only, should replace with a logger or another output
		 // cout << "Found duplicated school DBN key !!" << endl;
		 // cout << "\tNew (ignoring): " << school->dbn << " | " << school->name << endl;
		 // cout << "\tOld (keeping): " << school_map[school->dbn]->dbn << " | " << school_map[school->dbn]->name << endl;
		}
		else
		{
			school_map.insert(pair<std::string, School *>(school->dbn, school));
		}
	}

	void DataStorage::AddDataFromCsv(std::istream &csv_data)
	{
		string line;
		vector<tuple<unsigned int, unsigned int>> v_t_pos;
		// Remove the first line (csv header)
		getline(csv_data, line);
		// Iterates over each line
		while (getline(csv_data, line))
		{
			TokenizeSchoolData(line, v_t_pos);
			if (IsSchoolDataValid(line, v_t_pos))
				AddSchool(line, v_t_pos);
		}
	}

	unsigned int DataStorage::GetNumberOfAddedSchools()
	{
		return school_map.size();
	}

	std::map<std::string, School *> const &DataStorage::GetSchoolMap()
	{
		return school_map;
	}
};// namespace CollegeData