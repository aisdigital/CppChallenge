#pragma once

#include "IMenu.h"

class Menu : public IMenu {
public:
	Menu() = default;
	~Menu() = default;

	void run(const std::future<std::vector<Record>>& futureRecords) override;
};


