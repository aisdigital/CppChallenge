// Challenge C++ AISDigital

#include <iostream>
#include <fstream>

#include "college_data.h"
#include "main_methods.h"

#include <map>

using namespace std;
using namespace MainMethods;

int main(int argc, const char *argv[])
{
	string s_aux;
	unsigned int ui_aux;

	ShowInitialBanner();

	// Get input arguments
	string input_data_fullpath = argv[1];
	string output_dir_fullpath = argv[2];
	string output_data_fullpath = "";

	// Open and get input data file
	ifstream college_file;
	istream &college_data = OpenAndGetInputFileData(input_data_fullpath, college_file);

	// Read and store input file data
	CollegeData::DataStorage data_storage;
	data_storage.AddDataFromCsv(college_data);

	// Close input data file
	CloseInputFile(college_file);
	ShowDataPathLoaded(input_data_fullpath);

	// Manipulate stored data
	CollegeData::DataAnalysis data_analysis;

	// Create output directory
	CreateOutputDirectory(output_dir_fullpath);

	// Data is already loaded
	// Main menu loop
	while (true)
	{
		s_aux = ShowMainMenu();
		ui_aux = s_aux[0] - 48;// Char to int
		switch (ui_aux)
		{
		case 1:
			s_aux = GetSchoolNameToSearch();
			ui_aux = data_analysis.SearchByName(s_aux, data_storage);
			ShowUserSearchByNameResults(ui_aux, data_analysis.GetLastResult().str());
			s_aux = GetUserSaveChoice();
			if (s_aux != "yes" && s_aux != "y")
				break;
			s_aux = GetUserSaveFileName();
			output_data_fullpath = output_dir_fullpath + "/" + s_aux;
			SaveUserResults(output_data_fullpath, data_analysis.GetLastResult());
			break;
		case 2:
			s_aux = GetSchoolDbnToSearch();
			ui_aux = data_analysis.SearchByDbn(s_aux, data_storage);
			ShowUserSearchByDbnResults(ui_aux, data_analysis.GetLastResult().str());
			break;
		case 3:
			return 0;
		default:
			ShowUserMenuInvalidSelection();
			break;
		}
	}

	return 0;
}
