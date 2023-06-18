#pragma once

#include "ICSVParser.h"

class CSVParser : public ICSVParser {
public:
	CSVParser(const std::string& fileName);
	~CSVParser() = default;

	std::future<std::vector<Record>> parse() override;
};

