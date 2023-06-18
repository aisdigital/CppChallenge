#pragma once

#include <future>
#include <memory>
#include <string>

#include "ICSVParser.h"

class CSVParser : public ICSVParser {
public:
	CSVParser(const std::string& fileName);
	~CSVParser() = default;

	std::future<RecordsData> parse() override;
private:
	void parseCSV(std::shared_ptr<std::promise<RecordsData>> promise);
	std::string trim(const std::string& s);

	std::string fileName;
};

