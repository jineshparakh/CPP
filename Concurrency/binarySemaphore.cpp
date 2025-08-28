#include <iostream>
#include <semaphore>
#include <thread>


// 0 here tells semaphore is acquired
std::binary_semaphore
smphSignalMainToThread{0},
smphSignalThreadToMain{0};

void fun() {

    // wait for signal from main
    // by attempting to decrement the semaphore
    smphSignalMainToThread.acquire();

    std::cout << "[Thread]: Got the signal\n";

    std::cout << "[Thread]: Sending signal to main\n";

    smphSignalThreadToMain.release();
}

int main() {

    /*
        Mutex and semaphore
        --> Both are synchronization primitives

        Mutex:
        --> Single thread in critical section
        --> locking mechanism

        Semaphore:
        --> Multiple threads in critical section (counting semaphore)
        --> signaling mechanism

    */

    std::thread t1(&fun);

    std::cout << "[main]: sending signal to thread\n";
    // send signal to thread to start working
    smphSignalMainToThread.release();

    // wait until thread completes its task and signals back
    smphSignalThreadToMain.acquire();
    std::cout << "[main]: got signal back from thread\n";

    t1.join();
}