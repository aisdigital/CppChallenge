#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>

#include "main_methods.h"

using namespace std;

// Could also test this methods
// Could make at least two classes from this namespace

namespace MainMethods
{
	string GetUserInput()
	{
		string s_aux;
		getline(cin, s_aux);
		if (s_aux.empty())
			s_aux = "no";
		return s_aux;
	}

	void ShowInitialBanner()
	{
		cout << "\n";
		cout << "------------------------------\n";
		cout << "Starting the AIS C++ Challenge\n";
		cout << "------------------------------\n"
			 << endl;
	}

	void ShowDataPathLoaded(string const &data_file_path)
	{
		cout << "\n";
		cout << "Loaded data file at: ";
		cout << data_file_path << "\n"
			 << endl;
	}

	string ShowMainMenu()
	{
		cout << "\n";
		cout << "---------------------------\n";
		cout << "AIS C++ Challenge Main Menu\n";
		cout << "---------------------------\n";
		cout << "(1) Search by school Name\n";
		cout << "(2) Search by school DBN\n";
		cout << "(3) Exit\n\n";
		cout << "Enter your selection: ";
		return GetUserInput();
	}

	string GetSchoolDbnToSearch()
	{
		cout << "\n";
		cout << "Enter the School DBN (exact number): ";
		return GetUserInput();
	}

	string GetSchoolNameToSearch()
	{
		cout << "\n";
		cout << "Enter the School Name (similar names allowed): ";
		return GetUserInput();
	}

	string GetUserSaveChoice()
	{
		cout << "\n";
		cout << "Do you wanna save the results? (yes/No): ";
		return GetUserInput();
	}

	string GetUserSaveFileName()
	{
		cout << "\n";
		cout << "Enter the output file name to save the results: ";
		return GetUserInput();
	}

	void ShowUserSearchByDbnResults(unsigned int n, string const &str)
	{
		cout << "\n";
		cout << "Showing the " << n << " results from search by DBN:\n\n";
		cout << str << endl;
	}

	void ShowUserSearchByNameResults(unsigned int n, string const &str)
	{
		cout << "\n";
		cout << "Showing the " << n << " results from search by Name:\n\n";
		cout << str << endl;
	}

	void ShowUserMenuInvalidSelection()
	{
		cout << "\n";
		cout << "Invalid selection!"
			 << endl;
	}

	istream &OpenAndGetInputFileData(string &input_data_fullpath, ifstream &input_data_file)
	{
		input_data_file.open(input_data_fullpath);
		if (!input_data_file.is_open())
		{
			cout << "File \"" << input_data_fullpath << "\" not found!" << endl;
			exit;
		}
		return input_data_file;
	}

	void CloseInputFile(ifstream &input_data_file)
	{
		input_data_file.close();
	}

	void SaveUserResults(string &result_file_fullpath, stringstream &results)
	{
		ofstream result_file(result_file_fullpath);
		result_file << results.str();
		result_file.close();
		cout << "\n";
		cout << "File saved at: " << result_file_fullpath
			 << endl;
	}

	void CreateOutputDirectory(string &output_dir_fullpath)
	{
		int i_aux;
		// Simple solution
		// Should use boost::filesystem (integrate with cmake and conan?) or switch to C++17 and use experimental::filesystem ..
#if defined(_WIN32)
		i_aux = _mkdir(output_dir_fullpath.c_str());// Windows - Need to test
#else
		i_aux = mkdir(output_dir_fullpath.c_str(), 0733);// Unix - Working
#endif
	}

};// namespace MainMethods