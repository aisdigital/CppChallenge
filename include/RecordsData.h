#pragma once

#include <string>
#include <unordered_map>

// Aux struct to keep data read
struct Record {
	std::string dbn;
	std::string schoolName;
	int testTakers;
	int criticalReadingMean;
	int mathsMean;
	int writingMean;
};

class RecordsData {
public:
	unsigned int getRecordCount() const;
	Record getRecord(const std::string& key) const;
	Record& operator[](const std::string& key);

private:
	std::unordered_map<std::string, Record> records;
};
