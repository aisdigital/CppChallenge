#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

#include "SatResult.h"

class SatReader {
   public:
    // Start the worker thread to read the SAT CSV
    void startThread();

    // Returns a pointer to the next element read by the worker.
    // Returns null pointer if there aren't more elements.
    std::shared_ptr<SatResult> getNext();

    // Join the worker thread
    void join();

   private:
    std::mutex mutex;
    std::condition_variable producer_cv;  // The producer waits on this variable when it tries to add a new item to the buffer but it's full
    std::condition_variable consumer_cv;  // The consumer waits on this variable when it tries to get a item from the buffer but it's empty

    std::thread worker;
    bool hasWorkerStarted = false;
    bool hasWorkerFinished = false;

    const int maxBufferSize = 5;
    std::queue<std::shared_ptr<SatResult>> buffer;

    // The parameter reader is used to communicate between the worker and main thread
    static void work(SatReader* reader);
    static void addToBuffer(SatReader* reader, SatResult* result);
};
