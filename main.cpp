// Challenge C++ AISDigital

#include <memory>

#include "CSVParser.h"
#include "Menu.h"

int main() { 
	const std::string fileName = "data.csv";

	// Create an instance of the CSV parser
	std::unique_ptr<ICSVParser> csvParser = std::make_unique<CSVParser>(fileName);

	// Start the parsing asynchronously and get the future
	std::future<std::vector<Record>> futureRecords = csvParser->parse();

	// Create an instance of the menu
	std::unique_ptr<IMenu> menu = std::make_unique<Menu>();

	// Run the menu and wait for data processing
	menu->run(futureRecords);

	return 0;
}
