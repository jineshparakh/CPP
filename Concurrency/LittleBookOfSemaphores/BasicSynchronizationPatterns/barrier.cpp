#include <iostream>
#include <sstream>
#include <thread>
#include <vector>


int main() {

    /*
        The main issue with rendezvous is that it does not work for more than 2 threads.

        Problem statement:

        There are N threads.
        Each thread does:
        Rendezvous
        Critical Section


        Enforce that no thread can execute critical section until all threads have executed
        rendezvous


        NOTE: The barrier code below cannot be used more than once.
              See reusableBarrier.cpp
    */

    std::binary_semaphore mu(1);
    std::binary_semaphore barrier(0);
    int c = 0;
    const int MAX_THREADS = 10;

    auto threadFn = [&]() {

        std::ostringstream oss;
        oss << std::this_thread::get_id();
        std::string thread_id_str = oss.str();

        printf("Thread id: %s executing rendezvous\n", thread_id_str.c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));

        mu.acquire();
        c++;
        if (c == MAX_THREADS) {
            barrier.release();
        }
        mu.release();

        /*
            MOST IMP:
            This technique of successive acquire & release is called a TURNSTILE.
            It allows one thread to pass at a time or blocks all threads
        */
        barrier.acquire();
        barrier.release();

        printf("Thread id: %s executing critical section\n", thread_id_str.c_str());
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < MAX_THREADS; i++) {
        threads.emplace_back(std::thread(threadFn));
    }

    for (auto& thread : threads)
        thread.join();


    return 0;
}