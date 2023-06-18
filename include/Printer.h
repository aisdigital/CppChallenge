#pragma once

#include "IPrinter.h"

class Printer : public IPrinter {
public:
	Printer() = default;
	~Printer() = default;

	void printLoading() override;
	int printMain() override;
	std::string printSearchByDbn() override;
	std::string printSearchByName() override;
	void printRecord(const Record& record) override;
	char printOutputQuestion() override;
private:
	std::string trim(const std::string& s);
};


