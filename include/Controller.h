#pragma once

#include <memory>

#include "ICSVParser.h"
#include "IMenu.h"

class Controller {
public:
	Controller(std::unique_ptr<ICSVParser>&& parser,
			   std::unique_ptr<IMenu>&& menu);
	~Controller() = default;

	void run();
private:
	void initialize();

	std::unique_ptr<ICSVParser> parser;
	std::unique_ptr<IMenu> menu;
	std::future<RecordsData> parseFuture;
};
