#include <iostream>
#include <vector>
#include <thread>
#include <atomic>


// mutex = mutual exclusion
std::mutex gLock;

const int nThreads = 100;

static std::atomic<int> c = 0;

void counter() {
    c++;
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