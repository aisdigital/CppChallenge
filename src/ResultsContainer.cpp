#include "ResultsContainer.h"

#include "csv.h"

#include <algorithm>
#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>

bool ResultsContainer::Load(const std::string &path)
{
    try
    {
        io::CSVReader<6, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '"'>> csv(path.c_str());

        csv.read_header(io::ignore_missing_column, "DBN", "School Name", "Number of Test Takers", "Critical Reading Mean", "Mathematics Mean", "Writing Mean");

        std::string DBN;
        std::string schoolName;
        std::string numberOfTestTakers;
        std::string criticalReadingMean;
        std::string mathematicsMean;
        std::string writingMean;

        while (csv.read_row(DBN,
                            schoolName,
                            numberOfTestTakers,
                            criticalReadingMean,
                            mathematicsMean,
                            writingMean))
        {
            auto resultData = ResultData(DBN,
                                         schoolName,
                                         numberOfTestTakers,
                                         criticalReadingMean,
                                         mathematicsMean,
                                         writingMean);

            datas.insert(std::make_pair(DBN, resultData));
        }
    }
    catch (const std::exception &)
    {
        return false;
    }

    return true;
}

bool ResultsContainer::Save(const std::string &path, std::vector<ResultData> results)
{
    const std::string savePath = "./output/";

    struct stat info;

    if (stat(savePath.c_str(), &info) != 0)
    {
        mkdir(savePath.c_str(), 0777);
    }

    std::fstream csvOut;
    try
    {
        csvOut.open(savePath + path, std::ios::out);

        csvOut
            << "DBN, School Name, Number of Test Takers,"
            << "Critical Reading Mean, Mathematics Mean, Writing Mean"
            << std::endl;

        auto prepareFiled = [](const std::string &field) -> std::string {
            if (field.find('"') != std::string::npos ||
                field.find('\\') != std::string::npos ||
                field.find(',') != std::string::npos)
            {
                return "\"" + field + "\"";
            }

            return field;
        };

        for (const auto &result : results)
        {
            csvOut << prepareFiled(result.DBN) << ","
                   << prepareFiled(result.schoolName) << ","
                   << prepareFiled(result.numberOfTestTakers) << ","
                   << prepareFiled(result.criticalReadingMean) << ","
                   << prepareFiled(result.mathematicsMean) << ","
                   << prepareFiled(result.writingMean) << std::endl;
        }

        csvOut.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

std::vector<ResultData> ResultsContainer::SearchByDBN(const std::string &dbn)
{
    std::vector<ResultData> results;

    if (datas.find(dbn) != datas.end())
    {
        results.push_back(datas.at(dbn));
    }

    return results;
}

std::vector<ResultData> ResultsContainer::SearchByName(const std::string &name)
{
    std::vector<ResultData> results;

    for (const auto &data : datas)
    {
        if (data.second.schoolName.find(name) != std::string::npos)
        {
            results.push_back(data.second);
        }
    }

    if (!results.empty())
    {
        // Sort results by School Name
        std::sort(results.begin(), results.end());
    }

    return results;
}
