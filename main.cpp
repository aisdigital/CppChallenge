// Challenge C++ AISDigital

#include "Controller.h"
#include "CSVParser.h"
#include "Menu.h"

int main() { 
	const std::string fileName = "input/SAT__College_Board__2010_School_Level_Results";

	// Create an instance of the CSV parser and for the menu printer
	std::unique_ptr<ICSVParser> csvParser = std::make_unique<CSVParser>(fileName);
	std::unique_ptr<IMenu> menu = std::make_unique<Menu>();

	Controller control(std::move(csvParser), std::move(menu));
	control.run();

	return 0;
}
