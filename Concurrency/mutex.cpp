#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


// mutex = mutual exclusion
std::mutex gLock;

const int nThreads = 100;

static int c = 0;

void counter() {
    // RAII
    /*
        --> lock_guard is a light weight wrapper for owning
            mutex on a scoped basis
        --> lock is acquired the moment lock_guard object is created
        --> RAII semantics. Cannot explicitly unlock
        --> No copy constructor. Cannot copy
    */
    std::lock_guard<std::mutex> lk(gLock);
    c++;

    // Non RAII
    // gLock.lock();
    // c++;
    // gLock.unlock();
}

int main() {

    std::vector<std::thread> threads;
    for (int i = 0; i < nThreads; i++) {
        threads.push_back(std::thread(counter));
    };

    for (int i = 0; i < nThreads; i++) {
        threads[i].join();
    }

    std::cout << "Counter val: " << c << std::endl;

    return 0;
}