#include "CSVParser.h"

#include <fstream>
#include <thread>
#include <iostream>

CSVParser::CSVParser(const std::string& fileName) :
	fileName(fileName)
{
}

std::future<RecordsData> CSVParser::parse() {
	auto promise = std::make_shared<std::promise<RecordsData>>();
	auto future = promise->get_future();
	
	std::thread parsingThread(&CSVParser::parseCSV,this,promise);

	parsingThread.detach();
	return future;
}

void CSVParser::parseCSV(std::shared_ptr<std::promise<RecordsData>> promise) {
	RecordsData recordsData;
	std::ifstream input(fileName);

	std::string line;
	std::getline(input,line); // ignore first line

	while(std::getline(input,line)) {
		Record newRecord = {};
		auto pos = std::string::npos;

		pos = line.find(',');
		newRecord.dbn = trim(line.substr(0, pos));
		line = line.substr(pos + 1);

		pos = line.find(',');
		newRecord.schoolName = trim(line.substr(0, pos));
		line = line.substr(pos + 1);

		pos = line.find(',');
		newRecord.testTakers = std::stoi( line.substr(0, pos) );
		line = line.substr(pos + 1);

		pos = line.find(',');
		newRecord.criticalReadingMean = std::stoi( line.substr(0, pos) );
		line = line.substr(pos + 1);

		pos = line.find(',');
		newRecord.mathsMean = std::stoi( line.substr(0, pos) );
		line = line.substr(pos + 1);

		pos = line.find(',');
		newRecord.writingMean = std::stoi( line.substr(0, pos) );
		line = line.substr(pos + 1);

		recordsData[newRecord.dbn] = newRecord;
	}

	promise->set_value(std::move(recordsData));
}

std::string CSVParser::trim(const std::string& s) {
	auto pos = s.find_last_not_of(' ');
	return s.substr(0, pos + 1);
}
