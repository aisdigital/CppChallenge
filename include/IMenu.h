#pragma once

#include <future>
#include <vector>
#include "Record.h"

class IMenu {
public:
	virtual ~IMenu() = default;
	virtual void run(const std::future<std::vector<Record>>& futureRecords) = 0;
};

