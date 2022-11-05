#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

namespace MainMethods
{
	std::string GetUserInput();

	void ShowInitialBanner();

	void ShowDataPathLoaded(std::string const &data_file_path);

	std::string ShowMainMenu();

	std::string GetSchoolDbnToSearch();

	std::string GetSchoolNameToSearch();

	std::string GetUserSaveChoice();

	std::string GetUserSaveFileName();

	void ShowUserSearchByDbnResults(unsigned int n, std::string const &str);

	void ShowUserSearchByNameResults(unsigned int n, std::string const &str);

	void ShowUserMenuInvalidSelection();

	std::istream & OpenAndGetInputFileData(std::string &input_data_fullpath, std::ifstream & input_data_file);

	void CloseInputFile(std::ifstream & input_data_file);
	
	void SaveUserResults(std::string &result_file_fullpath, std::stringstream &results);

    void CreateOutputDirectory(std::string &output_dir_fullpath);
};// namespace MainMenu