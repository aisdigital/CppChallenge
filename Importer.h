#pragma once
#include "SchoolData.h"
#include "SchoolDataRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Importer
{
public:
	void ImportFile(string path);
	void SaveFile(string path, vector<SchoolData*> data);
	bool FileExists(string path);

};

