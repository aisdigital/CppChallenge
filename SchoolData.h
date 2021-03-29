#pragma once
#include<iostream>
#include<string>

using namespace std;

class SchoolData
{
private:
	string mDBN;
	string mSchoolName;
	int mNumberOfTestTakers;
	int mCriticalReadingMean;
	int mMathematicsMean;
	int mWritingMean;

public:
	
	SchoolData(string DBN, string schoolName, int numberOfTestTakers, int criticalReadingMean, int mathematicsMean, int writingMean);
	
	void DisplayData();

	bool ContainsName(string name);
	bool ContainsDBN(string name);
	bool ExactDBN(string name);
	
	string SaveFormat();

	//operators for the sorting
	bool operator > (const SchoolData& other) const
	{
		return (mSchoolName > other.mSchoolName);
	}
	bool operator < (const SchoolData& other) const
	{
		return (mSchoolName < other.mSchoolName);
	}
};

