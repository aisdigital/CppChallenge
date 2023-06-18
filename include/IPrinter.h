#pragma once

#include <string>

#include "RecordsData.h"

class IPrinter {
public:
	virtual ~IPrinter() = default;
	virtual void printLoading() = 0;
	virtual int printMain() = 0;
	virtual std::string printSearchByDbn() = 0;
	virtual std::string printSearchByName() = 0;
	virtual void printRecord(const Record& record) = 0;
	virtual char printOutputQuestion() = 0;
};

