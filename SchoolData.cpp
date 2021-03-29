#include "SchoolData.h"

SchoolData::SchoolData(string DBN, string schoolName, int numberOfTestTakers, int criticalReadingMean, int mathematicsMean, int writingMean)
{
	mDBN = DBN;
	mSchoolName = schoolName;
	mNumberOfTestTakers = numberOfTestTakers;
	mCriticalReadingMean = criticalReadingMean;
	mMathematicsMean = mathematicsMean;
	mWritingMean = writingMean;
}

void SchoolData::DisplayData()
{
	cout << "DBN: " << mDBN + " / Name: " << mSchoolName << " / # of Test Takers: " << mNumberOfTestTakers << " / Critical Reading Mean: " << mCriticalReadingMean << " / Mathematics Mean: " << mMathematicsMean << " / Writing Mean: " << mWritingMean << "\n";
}

bool SchoolData::ContainsName(string name)
{
	if (mSchoolName.find(name) != string::npos)
	{
		return true;
	}
	return false;
}

bool SchoolData::ContainsDBN(string name)
{
	if (mDBN.find(name) != string::npos)
	{
		return true;
	}
	return false;
}

bool SchoolData::ExactDBN(string name)
{
	if (mDBN.compare(name) == 0)
	{
		return true;
	}
	return false;
}

string SchoolData::SaveFormat()
{
	string result;

	result.append(mDBN);
	result.append(",");
	if (mSchoolName.find(",") != string::npos)
	{
		result.append("\"");
	}
	result.append(mSchoolName);
	if (mSchoolName.find(",") != string::npos)
	{
		result.append("\"");
	}
	result.append(",");
	result.append(to_string(mNumberOfTestTakers));
	result.append(",");
	result.append(to_string(mCriticalReadingMean));
	result.append(",");
	result.append(to_string(mMathematicsMean));
	result.append(",");
	result.append(to_string(mWritingMean));

	return result;
}

