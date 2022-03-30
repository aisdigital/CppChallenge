#ifndef CSVFILE_H
#define CSVFILE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class CsvFile {
public:
    static CsvFile* getInstance();

    void deleteInstance();

    void setCsvFile(vector<string> newCsvFile);

    vector<string> getCsvFile();

private:
    CsvFile();
    ~CsvFile();
    static CsvFile* m_instance;
    vector<string> m_csvFile;
};

#endif // CSVFILE_H