#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <chrono>
#include <string>

class ThreadPool {
private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;

    std::mutex qMutex;
    std::condition_variable cv;

    bool isRunning{true};


public:
    ThreadPool(int numThreads) {

        for (int i = 0; i < numThreads; i++) {
            auto threadFn = [this]() {
                while (true) {
                    std::unique_lock<std::mutex> lock(qMutex);
                    cv.wait(lock, [this]() {
                        return !isRunning || tasks.size() > 0;
                    });

                    if (!isRunning && tasks.size() == 0) {
                        return;
                    }


                    auto task = std::move(tasks.front());
                    tasks.pop();

                    cv.notify_one();

                    lock.unlock();
                    task();
                }
            };
            threads.push_back(std::thread(threadFn));
        }


    }

    ~ThreadPool() {
        std::unique_lock<std::mutex> lock(qMutex);
        isRunning = false;
        cv.notify_all();

        lock.unlock();

        for (auto& i : threads) {
            i.join();
        }
    }

    void enqueueTask(auto fn) {
        std::unique_lock<std::mutex> lock(qMutex);
        tasks.push(std::move(fn));
        cv.notify_all();
    }
};

std::string getThreadId() {
    auto myid = std::this_thread::get_id();
    std::stringstream ss;
    ss << myid;
    std::string s = ss.str();

    return s;
}

//  g++ -Wall -g -fsanitize=thread -std=c++23 threadpool.cpp
int main() {

    ThreadPool pool(4);

    for (int i = 0; i < 40; i++) {
        pool.enqueueTask([i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::string s = "Task " + std::to_string(i) + " done by tid: ";
            s += getThreadId();
            s += "\n";
            std::cout << s;
        });
    }
}