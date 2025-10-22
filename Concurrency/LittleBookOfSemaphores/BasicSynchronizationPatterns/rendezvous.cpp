#include <iostream>
#include <semaphore>
#include <thread>
#include <sstream>

int main() {

    /*
        Rendezvous:
        The synchronization point for threadA and threadB is called rendezvous.
        Neither is allowed to proceed until both have arrived at that point

        threadA         threadB
        CHAOS           CHAOS
                SYNC
        CHAOS           CHAOS

        Problem statement:
            We want to guarantee that a1 happens before b2 and b1 happens before a2.
            No other constraints
                ==> (a1, b1) < (a2, b2)
                ==> Relative order of a1, b2 & a2, b2 does not matter

    */

    std::binary_semaphore aArrived(0);
    std::binary_semaphore bArrived(0);

    auto threadAFn = [&]() {
        std::ostringstream oss;
        oss << std::this_thread::get_id();
        std::string thread_id_str = oss.str();
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        printf("Thread A(tid: %s) doing task A1\n", thread_id_str.c_str());

        aArrived.release();
        bArrived.acquire();

        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        printf("Thread A(tid: %s) doing task A2\n", thread_id_str.c_str());
    };

    auto threadBFn = [&]() {
        std::ostringstream oss;
        oss << std::this_thread::get_id();
        std::string thread_id_str = oss.str();
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        printf("Thread B(tid: %s) doing task B1\n", thread_id_str.c_str());


        bArrived.release();
        aArrived.acquire();

        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
        printf("Thread B(tid: %s) doing task B2\n", thread_id_str.c_str());
    };

    std::thread t1(threadAFn);
    std::thread t2(threadBFn);

    t1.join();
    t2.join();

    return 0;
}