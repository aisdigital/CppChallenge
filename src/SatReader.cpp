#include "SatReader.h"

#include <fstream>
#include <iostream>

#include "CsvParser.h"

void SatReader::startThread() {
    if (hasWorkerStarted) {
        std::cout << "[Error] The reader worker already started." << std::endl;
        exit(1);
    }

    hasWorkerStarted = true;
    hasWorkerFinished = false;
    worker = std::thread(work, this);
}

std::shared_ptr<SatResult> SatReader::getNext() {
    std::unique_lock<std::mutex> lk(mutex);

    while (buffer.empty()) {
        if (hasWorkerFinished) {
            return nullptr;
        }

        consumer_cv.wait(lk);
    }

    std::shared_ptr<SatResult> data = buffer.front();
    buffer.pop();

    producer_cv.notify_all();

    lk.unlock();

    return data;
}

void SatReader::join() {
    worker.join();
}

void SatReader::work(SatReader* reader) {
    // Functions to map columns of the CSV to the SatResult's properties
    const std::map<std::string, std::function<void(SatResult*, std::string)>> columnSetters = {
        {"DBN", [](SatResult* result, std::string value) { result->Dbn = value; }},
        {"School Name", [](SatResult* result, std::string value) { result->SchoolName = value; }},
        {"Number of Test Takers", [](SatResult* result, std::string value) { result->NumberOfTestTakers = value; }},
        {"Critical Reading Mean", [](SatResult* result, std::string value) { result->CriticalReadingMean = value; }},
        {"Mathematics Mean", [](SatResult* result, std::string value) { result->MathematicsMean = value; }},
        {"Writing Mean", [](SatResult* result, std::string value) { result->WritingMean = value; }}};

    try {
        std::ifstream file("input/SAT__College_Board__2010_School_Level_Results.csv");
        std::string line;

        // Read header
        std::getline(file, line);
        CsvParser<SatResult> csvParser(line, columnSetters);

        while (std::getline(file, line)) {
            auto result = csvParser.parseLine(line);
            addToQueue(reader, result);
        }

        reader->hasWorkerFinished = true;

        // Wake the consumer if it's waiting for more data
        std::unique_lock<std::mutex> lk(reader->mutex);
        reader->consumer_cv.notify_all();
        lk.unlock();

    } catch (std::exception& ex) {
        std::cout << "[Error] An error occurred while reading the CSV." << std::endl;
        std::cout << ex.what() << std::endl;
        exit(1);
    }
}

void SatReader::addToQueue(SatReader* reader, SatResult* result) {
    std::unique_lock<std::mutex> lk(reader->mutex);

    while (reader->buffer.size() >= reader->maxBufferSize) {
        reader->producer_cv.wait(lk);
    }

    reader->buffer.emplace(result);
    reader->consumer_cv.notify_all();

    lk.unlock();
}