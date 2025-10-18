#include <iostream>
#include <semaphore>

class RWMutex {
private:
    // keeps track of how many readers are there in the room
    // We track the number of reads so that we can give special work to the
    // first arrived reader and the last gone reader
    // This is called LIGHTSWITCH pattern
    int numReaders;
    // roomEmpty is 1 if there are no readers/writers in the critical section
    std::binary_semaphore roomEmpty;
    // To protect numReaders
    std::binary_semaphore mutex;

    // Signal that a writer has arrived
    std::binary_semaphore writerArrived;

public:
    RWMutex(): numReaders(0), roomEmpty(1), mutex(1), writerArrived(0) {

    }
    void RLock() {
        /*
            These two lines below are REALLY IMPORTANT to prevent starvation.

            If a writer has arrived, no other reader should be allowed to enter.
            This acts as a TURNSTILE.
        */
        writerArrived.acquire();
        writerArrived.release();

        mutex.acquire();
        numReaders++;
        if (numReaders == 1) {
            roomEmpty.acquire();
        }
        mutex.release();
    }

    void RUnlock() {
        mutex.acquire();
        numReaders--;
        if (numReaders == 0) {
            roomEmpty.release();
        }
        mutex.release();
    }

    void Lock() {
        writerArrived.acquire();
        roomEmpty.acquire();
    }

    void Unlock() {
        writerArrived.release();
        roomEmpty.release();
    }
};



int main() {

    /*
        Requirements:
        1. Any number of readers can be in the critical section simultaneously.
        2. Writers must have exclusive access to the critical section.
        3. When a writer arrives, the existing readers can finish, but no additional readers may enter


        Exclusion pattern in this case is called "categorical mutual exclusion"


    */
    RWMutex mu;

    return 0;
}