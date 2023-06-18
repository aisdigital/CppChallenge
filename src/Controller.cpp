#include "Controller.h"

#include <filesystem>
#include <fstream>
#include <iostream>

Controller::Controller(std::unique_ptr<ICSVParser>&& parser,
					   std::unique_ptr<IPrinter>&& printer) :
	parser(std::move(parser)), printer(std::move(printer))
{
}

void Controller::run() {
	initialize();

	auto records = parseFuture.get();

	while(true) {
		std::vector<Record> searchResult = {};
		auto op = printer->printMain();

		if(op == 1) {
			try {
				auto name = printer->printSearchByName();
				searchResult = records.searchByName(name);
				std::cout << "is search empty? " << (int)searchResult.empty() << std::endl;
			}
			catch(std::exception& e) {
				std::cerr << "Error: failed to search by name!" << std::endl;
				continue;
			}
		} else if(op == 2) {
			try {
				auto dbn = printer->printSearchByDbn();
				searchResult = records.searchByDbn(dbn);
			}
			catch(std::exception& e) {
				std::cerr << "Error: failed to search by DBN!" << std::endl;
				continue;
			}
		} else if(op == 3) {
			break;
		}

		for(const auto& record: searchResult) {
			printer->printRecord(record);
		}

		if(op == 1) {
			char saveOp = printer->printOutputQuestion();
			if(saveOp == 'y') {
				saveOutput("output.csv", searchResult);
			}
		}
	}
}

void Controller::initialize() {
	printer->printLoading();
	parseFuture = parser->parse();
}

void Controller::saveOutput(const std::string& fileName, const std::vector<Record>& records) {
	constexpr char separator = ',';
	const std::string dirName = "output";

	if(!std::filesystem::exists(dirName)) {
		std::filesystem::create_directory(dirName);
	}

	const std::string filePath = dirName + "/" + fileName;
	std::ofstream file(filePath);

	file << "DBN,School Name,Test Takers,Critical Reading Mean,Maths Mean,Writing Mean\n";

	if(file.is_open()) {
		for(const auto& record : records) {
			file << record.dbn << separator;
			file << record.schoolName << separator;

			if(record.testTakers != 0) {
				file << record.testTakers << separator;
			} else {
				file << separator;
			}

			if(record.criticalReadingMean != 0) {
				file << record.criticalReadingMean << separator;
			} else {
				file << separator;
			}

			if(record.mathsMean != 0) {
				file << record.mathsMean << separator;
			} else {
				file << separator;
			}

			if(record.writingMean != 0) {
				file << record.writingMean << separator;
			} else {
				file << separator;
			}

			file << std::endl;
		}

		file.close();
		std::cout << "Output saved to file: " << fileName << std::endl;
	} else {
		std::cerr << "Failed to open output file!" << std::endl;
	}
}
