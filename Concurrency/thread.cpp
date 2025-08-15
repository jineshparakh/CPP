#include <iostream>
#include <thread> // since C++11
#include <vector>

void test(int x) {
    std::cout << "Hello from thread" << std::endl;
    std::cout << "Argument passed: " << x << std::endl;
}

int main() {

    /*
        "Thread" is one of the ways to achieve concurrency.
        Thread is a light weight process

        --> A thread allows us to execute two control flows at
        the same time
        --> The "main thread" is the place where our C++ program starts


        High level overview of thread:

        --> A single process can have many threads
        --> Each thread shares the same code, data and kernel contexts,
            shared libraries
        --> Every thread has its own thread id (TID)
        --> A thread has its own logical control flow
        --> A thread has its own stack for local variables
        --> Every thread has its own stack pointer, program counter,
            data registers, condition codes

    */

    // Create a new thread and pass function arguments
    std::thread myThread(&test, 100);

    /*
        Join with the main thread
        "Hey main thread, wait till myThread finishes before executing further"
    */
    myThread.join();

    // Continue main thread execution
    std::cout << "Hello from main thread" << std::endl;


    // Thread using lambda
    auto lambda = [](int n) {
        std::cout << "Hello from lambda thread" << std::endl;
        std::cout << "Argument passed to lambda thread: " << n << std::endl;
    };

    std::thread myThread2(lambda, 200);
    myThread2.join();


    // launching multiple threads
    auto lambda2 = [](int n) {
        std::cout << "Hello from lambda2 thread, tid: " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed to lambda2 thread: " << n << std::endl;
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread(lambda2, i));
    }

    for (int i = 0; i < 5; i++) {
        threads[i].join();
    }

    return 0;
}