#include <iostream>
#include <semaphore.h> // semaphore.h has legacy semaphore, semaphore has modern semaphore(>= C++20)
#include <mutex>
#include <thread>
#include <vector>


// define semaphore
sem_t sem1, sem2;

std::mutex mu;
int cWorker1 = 2;



/*
    Semaphore operations:

    1. sem_wait:
        --> Used by a thread to acquire a resource or wait for a signal
        --> Decrements semaphore value

    2. sem_post:
        --> Used by a thread to release a resource os signal to a wait
        --> Increments semaphore value
*/

void worker1() {
    sem_wait(&sem1);

    std::cout << "A";

    mu.lock();
    cWorker1--;
    if (cWorker1 == 0) {
        sem_post(&sem2);
    }
    mu.unlock();
}

void worker2() {
    sem_wait(&sem2);

    std::cout << "B";

    mu.lock();
    cWorker1 = 2;
    sem_post(&sem1);
    sem_post(&sem1);
    mu.unlock();
}

int main() {
    /*
        Example:
        Say you want to print AABAABAAB... for 10 pairs

    */
    /*
        Initialize semaphore

        Args:
        1. __sem: Semaphore you want to initialize
        2. __pshared: This controls semaphore's scope.
                      0 - inter thread sharing
                          can be a global variable or allocated on the heap
                      !=0 - inter process sharing
                            must have shared memory allocation
        3. __value: Initial value of semaphore counter
                    value > 0: semaphore is "unlocked" and waiting threads will not block
                               immediately. COUNTING SEMAPHORE
                    value = 0: semaphore is "locked," and the first thread to call sem_wait()
                               will block until another thread calls sem_post() to increment the value.
                    value = 1: A special case that creates a binary semaphore, which behaves like a mutex.
                               The first thread to call sem_wait() succeeds, and the next thread blocks.
    */
    sem_init(&sem1, 0, 2);
    sem_init(&sem2, 0, 0);

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(std::thread(worker1));
        threads.push_back(std::thread(worker2));
        threads.push_back(std::thread(worker1));
    }

    for (int i = 0; i < int(threads.size()); i++) {
        threads[i].join();
    }
}