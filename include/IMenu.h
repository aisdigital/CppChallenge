#pragma once

#include <string>

class IMenu {
public:
	virtual ~IMenu() = default;
	virtual void printLoading() = 0;
	virtual int printMain() = 0;
	virtual std::string printSearchByDbn() = 0;
	virtual std::string printSearchByName() = 0;
};

