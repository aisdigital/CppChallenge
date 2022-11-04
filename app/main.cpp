// Challenge C++ AISDigital

#include <iostream>
#include <fstream>

#include "college_data.h"

using namespace std;

int main(int argc, const char *argv[])
{
	// Open input file
	string data_fullpath = argv[1];
	ifstream college_file(data_fullpath);
	if (!college_file.is_open())
	{
		cout << "File not found!" << endl;
		return 0;
	}
	cout << "File " << data_fullpath << " successfully open!" << endl;

	// Read and store input file data
	CollegeData::DataStorage data_storage;
	data_storage.AddDataFromCsv(college_file);
	college_file.close();

	return 0;
}