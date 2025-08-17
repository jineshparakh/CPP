#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>

int main() {

    /*
        Condition variables are used for two reasons:
        1. Notify other threads
        2. Waiting for some conditions

        Condition variable allows running threads to wait on some
        conditions and once those conditions are met the waiting thread
        is notified using:
        a. notify_one()
        b. notify_all()

        Mutex is necessary for using condition variable

        NOTE:
        This can be a good use case for Producer/Consumer problems

    */

    std::mutex gLock;
    // similar to sync.Cond in Golang
    std::condition_variable gConditionVariable;

    int result = 0;
    bool notified = false;


    // Worker thread
    std::jthread worker([&]() {
        {
            std::unique_lock<std::mutex> lock(gLock);

            result = 33;
            notified = true;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "Worker: work complete\n";
        gConditionVariable.notify_one();
        std::cout << "Worker: notified\n";

    });

    // reporter thread
    std::jthread reporter([&]() {
        std::unique_lock<std::mutex> lock(gLock);

        // Two ways to wait
        // Way1
        gConditionVariable.wait(lock, [&] {return notified == true; });

        // Way2
        // if (!notified) {
        //     gConditionVariable.wait(lock);
        // }

        std::cout << "Reporter: result: " << result << "\n";


    });


    return 0;
}