#pragma once

#include <future>
#include <vector>
#include "Record.h"

class ICSVParser {
public:
	virtual ~ICSVParser() = default;
	virtual std::future<std::vector<Record>> parse() = 0;
};

