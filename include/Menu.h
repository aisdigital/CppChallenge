#pragma once

#include "IMenu.h"

class Menu : public IMenu {
public:
	Menu() = default;
	~Menu() = default;

	void printLoading() override;
	int printMain() override;
	std::string printSearchByDbn() override;
	std::string printSearchByName() override;
};


