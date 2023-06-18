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
		std::string entry;

		entry = getFieldEntry(line);
		newRecord.dbn = entry;

		entry = getFieldEntry(line);
		newRecord.schoolName = entry;

		entry = getFieldEntry(line);
		newRecord.testTakers = entry.empty() ? 0 : std::stoi(entry);

		entry = getFieldEntry(line);
		newRecord.criticalReadingMean = entry.empty() ? 0 : std::stoi(entry);

		
		entry = getFieldEntry(line);
		newRecord.mathsMean = entry.empty() ? 0 : std::stoi(entry);

		entry = getFieldEntry(line);
		newRecord.writingMean = entry.empty() ? 0 : std::stoi(entry);

		recordsData[newRecord.dbn] = newRecord;
	}

	promise->set_value(std::move(recordsData));
}

std::string CSVParser::getFieldEntry(std::string& line) {
    std::string entry;

	if(line.empty()) {
		return entry;
	}

	if(line[0] == '"') {
		auto pos = line.find('"', 1);
		if(pos != std::string::npos) {
			entry = trim(line.substr(1, pos - 1));
			line = line.substr(pos + 1);
		}
	} else {
		auto pos = line.find(',');
		entry = trim(line.substr(0, pos));
		line = line.substr(pos + 1);
	}

    return entry;
}

std::string CSVParser::trim(const std::string& s) {
	auto pos = s.find_last_not_of(' ');
	return s.substr(0, pos + 1);
}

