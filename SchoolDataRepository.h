#pragma once
#include "SchoolData.h"
#include<vector>
//Singleton to hold the imported file
class SchoolDataRepository
{
private:
	static SchoolDataRepository* mInstance;
	std::vector<SchoolData*> schools;

public:
	static SchoolDataRepository* GetInstance();
	
	int GetSize() { return schools.size(); }

	void AddSchool(SchoolData* school) { schools.push_back(school); }

	vector<SchoolData*> GetSchools() { return schools; }


};


