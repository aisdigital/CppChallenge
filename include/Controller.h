#pragma once

#include <memory>

#include "ICSVParser.h"
#include "IPrinter.h"

class Controller {
public:
	Controller(std::unique_ptr<ICSVParser>&& parser,
			   std::unique_ptr<IPrinter>&& printer);
	~Controller() = default;

	void run();
private:
	void initialize();
	void saveOutput(const std::string& fileName, const std::vector<Record>& records);

	std::unique_ptr<ICSVParser> parser;
	std::unique_ptr<IPrinter> printer;
	std::future<RecordsData> parseFuture;
};
