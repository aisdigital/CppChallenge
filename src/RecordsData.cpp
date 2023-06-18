#include "RecordsData.h"

unsigned int RecordsData::getRecordCount() const {
	return records.size();
}

Record RecordsData::getRecord(const std::string& key) const {
	return records.at(key);
}

Record& RecordsData::operator[](const std::string& key) {
	return records[key];
}
