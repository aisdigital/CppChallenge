// Challenge C++ AISDigital

#include "Controller.h"
#include "CSVParser.h"
#include "Printer.h"

int main() { 
	const std::string fileName = "input/SAT__College_Board__2010_School_Level_Results.csv";

	// Create an instance of the CSV parser and for the printer printer
	std::unique_ptr<ICSVParser> csvParser = std::make_unique<CSVParser>(fileName);
	std::unique_ptr<IPrinter> printer = std::make_unique<Printer>();

	Controller control(std::move(csvParser), std::move(printer));
	control.run();

	return 0;
}
