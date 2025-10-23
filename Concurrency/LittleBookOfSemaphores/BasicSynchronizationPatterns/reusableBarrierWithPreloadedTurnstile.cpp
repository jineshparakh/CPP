#include <iostream>
#include <sstream>
#include <thread>
#include <vector>


int main() {

    /*
        Problem statement:
        Rewrite the barrier solution so that after all the threads have passed
        through, the turnstile is locked again
    */

    std::binary_semaphore mu(1);
    int count = 0;
    const int MAX_THREADS = 10;

    std::counting_semaphore<MAX_THREADS> barrier(0);
    std::counting_semaphore<MAX_THREADS> barrier2(0);

    auto threadFn = [&]() {

        for (int i = 0; i < 5; i++) {
            std::ostringstream oss;
            oss << std::this_thread::get_id();
            std::string thread_id_str = oss.str();

            printf("Thread id: %s executing rendezvous\n", thread_id_str.c_str());
            std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));

            mu.acquire();
            count++;
            if (count == MAX_THREADS) {
                for (int i = 0; i < MAX_THREADS; i++) {
                    barrier.release();
                }
            }
            mu.release();

            barrier.acquire();

            printf("Thread id: %s executing critical section\n", thread_id_str.c_str());



            mu.acquire();
            count--;
            if (count == 0) {
                for (int i = 0; i < MAX_THREADS; i++) {
                    barrier2.release();
                }
            }
            mu.release();

            barrier2.acquire();

            printf("Thread id: %s proceeding to next iteration\n", thread_id_str.c_str());
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < MAX_THREADS; i++) {
        threads.emplace_back(std::thread(threadFn));
    }

    for (auto& thread : threads)
        thread.join();

    return 0;
}