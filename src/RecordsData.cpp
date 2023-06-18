#include "RecordsData.h"

#include <algorithm>

unsigned int RecordsData::getRecordCount() const {
	return records.size();
}

Record RecordsData::getRecord(const std::string& key) const {
	return records.at(key);
}

Record& RecordsData::operator[](const std::string& key) {
	return records[key];
}

std::vector<Record> RecordsData::searchByName(const std::string& name) {
	std::vector<Record> result;

	for(const auto& [dbn, record] : records) {
		if(record.schoolName == name) {
			result.push_back(record);
		}
	}

	std::sort(result.begin(), result.end(),
			  [](const Record& a, const Record& b) {
				  return a.schoolName < b.schoolName;
			  });

	return result;
}

std::vector<Record> RecordsData::searchByDbn(const std::string& dbn) {
    std::vector<Record> result;
	result.push_back(records[dbn]);
    return result;
}
