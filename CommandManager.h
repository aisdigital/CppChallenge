#pragma once
#include"SchoolData.h"
#include"SchoolDataRepository.h"
#include"Importer.h"

#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//Vector Sorter
struct Sorter
{
	bool operator()(const SchoolData* lhs, const SchoolData* rhs) const
	{
		return *lhs < *rhs;
	}
};


class CommandManager
{
private:
	Importer* importer;
	vector<SchoolData*> searchResult;
	vector<SchoolData*> GetSearchResult() { return searchResult; }

	void SearchByName(string term);
	void SearchByDBN(string term, bool exact);

	void ShowSearchResult();

	void SearchByNamePrompt();
	void SearchByDBNPrompt();

public:
	void MainLoop();

};

