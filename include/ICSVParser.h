#pragma once

#include <future>
#include <vector>

#include "RecordsData.h"

class ICSVParser {
public:
	virtual ~ICSVParser() = default;
	virtual std::future<RecordsData> parse() = 0;
};

