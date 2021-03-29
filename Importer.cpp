#include "Importer.h"

using namespace std;

void Importer::ImportFile(string path)
{
	fstream fin;

	fin.open(path, ios::in);

	vector<string> row;
	string line, word;
	bool hasComma, ignoreNext;
	getline(fin, line);
	while (fin)
	{
		hasComma = false;
		ignoreNext = false;
		int numberOfCommas = 0;
		int startingPoint = 0;
		row.clear();
		getline(fin, line);
		if (line == "")
		{
			break;
		}
		int end = line.size();

		for (int i = 0; i < line.size() + 1; i++)
		{
			if (line[i] == '"')
			{
				if (!hasComma)
				{
					hasComma = true;
					startingPoint++;
				}
				else
				{
					hasComma = false;
					int size = i - startingPoint - 1;
					word = line.substr(startingPoint, size);
					row.push_back(word);
					i++;
					startingPoint = i + 1;
					ignoreNext = true;
				}
			}
			if (i == end)
			{
				int size = i - startingPoint;
				word = line.substr(startingPoint, size);
				if (word == "")
				{
					word = "0";
				}
				row.push_back(word);
			}
			if (ignoreNext)
			{
				ignoreNext = false;
			}
			else if (line[i] == ',' && !hasComma)
			{
				int size = i - startingPoint;
				word = line.substr(startingPoint, size);
				if (word == "")
				{
					word = "0";
				}
				row.push_back(word);
				startingPoint = i + 1;
			}
		}
		SchoolDataRepository::GetInstance()->AddSchool(new SchoolData(row[0], row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), stoi(row[5])));
	}
	fin.close();
}

void Importer::SaveFile(string path, vector<SchoolData*> data)
{
	fstream fin;

	fin.open(path, ios::out);
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		string line = data[i]->SaveFormat();
		fin << line << "\n";
	}
	fin.close();
}

bool Importer::FileExists(string path)
{
	fstream fin;

	return fin.good();
}


