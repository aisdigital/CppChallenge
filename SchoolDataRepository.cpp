#include "SchoolDataRepository.h"

SchoolDataRepository* SchoolDataRepository::mInstance = nullptr;


SchoolDataRepository* SchoolDataRepository::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new SchoolDataRepository();
	}
	return mInstance;
}

