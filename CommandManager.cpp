#include "CommandManager.h"
#include<Windows.h>
#include <direct.h>
#define GetCurrentDir _getcwd

string GetDirectoryPath() {
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

//Search engines
void CommandManager::SearchByName(string term)
{
	vector<SchoolData*> base = SchoolDataRepository::GetInstance()->GetSchools();
	int size = base.size();
	for (int i = 0; i < size; i++)
	{
		if (base[i]->ContainsName(term))
		{
			searchResult.push_back(base[i]);
		}
	}
	sort(searchResult.begin(), searchResult.end(), Sorter());
}
void CommandManager::SearchByDBN(string term, bool exact)
{
	vector<SchoolData*> base = SchoolDataRepository::GetInstance()->GetSchools();
	int size = base.size();
	if (exact)
	{
		for (int i = 0; i < size; i++)
		{
			if (base[i]->ExactDBN(term))
			{
				searchResult.push_back(base[i]);
				//DBM is supposed to be unique, but there are some repeated DBN (see 04M610) so I left the break out.
				//break;
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (base[i]->ContainsDBN(term))
			{
				searchResult.push_back(base[i]);
			}
		}
	}
	sort(searchResult.begin(), searchResult.end(), Sorter());
}

//Displays results
void CommandManager::ShowSearchResult()
{
	if (searchResult.size() == 0)
	{
		cout << "No results found";
	}
	else
	{
		for (int i = 0; i < searchResult.size(); i++)
		{
			searchResult[i]->DisplayData();
		}
	}
}

//Command Prompts
void CommandManager::SearchByNamePrompt()
{
	string input = "";
	cout << "Please type the name you want to search: \n";
	cin >> input;
	SearchByName(input);
	ShowSearchResult();
	cout << "\n";
	cout << "Do you wish to save the results? \n";
	input = "";
	cin >> input;
	if (input.compare("yes") == 0)
	{
		string path = GetDirectoryPath() + "\\output\\SavedSchools.csv";
		cout << "Saving to " << path << ".\n";
		importer->SaveFile(path, searchResult);
	}
}
void CommandManager::SearchByDBNPrompt()
{
	bool exact;
	string input = "";
	while (input.compare("yes") != 0 && input.compare("no") != 0)
	{
		cout << "Do you want to search for an exact match of the DBN?\n";
		cin >> input;
	}
	if (input.compare("yes") == 0)
	{
		exact = true;
	}
	else
	{
		exact = false;
	}
	input = "";
	cout << "Please type the BDN you want to search: \n";
	cin >> input;
	SearchByDBN(input, exact);
	ShowSearchResult();
}

//Main Loop
void CommandManager::MainLoop()
{
	string path = GetDirectoryPath() + "\\input\\SAT__College_Board__2010_School_Level_Results.csv";
	importer = new Importer();
	importer->ImportFile(path);
	bool looping = true;
	int selection = 0;
	string input;
	while (looping)
	{
		cout << "Welcome to the School Databank, please press your selection:\n";
		while (selection < 1 || selection > 3)
		{
			cout << "1. Search School By Name\n";
			cout << "2. Search School By DBN\n";
			cout << "3. Exit Program.\n";

			cin >> input;
			try
			{
				selection = stoi(input);
			}
			catch (const std::exception&)
			{
				selection = 0;
			}			
			if (selection == 1)
			{
				SearchByNamePrompt();
			}
			else if (selection == 2)
			{
				SearchByDBNPrompt();
			}
			else if (selection == 3)
			{
			looping = false;
			break;
			}
			else
			{
			cout << "Invalid Selection \n \n";
			}
			selection = 0;
		}
	}
}
