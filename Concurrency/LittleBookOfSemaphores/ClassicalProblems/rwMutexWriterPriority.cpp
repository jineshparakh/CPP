#include <iostream>
#include <semaphore>

class RWMutex {
private:
    int numReaders;
    std::binary_semaphore rMutex;

    int numWriters;
    std::binary_semaphore wMutex;

    std::binary_semaphore roomEmpty;

public:
    RWMutex(): numReaders(0), rMutex(1), numWriters(0), wMutex(1), roomEmpty(1) {

    }

    void RLock() {
        wMutex.acquire();
        wMutex.release();

        rMutex.acquire();
        numReaders++;
        if (numReaders == 1) {
            roomEmpty.acquire();
        }
        rMutex.release();
    }

    void RUnlock() {
        rMutex.acquire();
        numReaders--;
        if (numReaders == 0) {
            roomEmpty.release();
        }
        rMutex.release();
    }

    void Lock() {

        wMutex.acquire();
        numWriters++;
        if (numWriters == 1) {
            rMutex.acquire();
        }
        wMutex.release();

        roomEmpty.acquire();
    }

    void Unlock() {

        wMutex.acquire();
        numWriters--;
        if (numWriters == 0) {
            rMutex.release();
        }
        wMutex.release();

        roomEmpty.release();
    }

};

int main() {
    RWMutex mu;

    mu.Lock();
    mu.Unlock();

    mu.RLock();
    mu.RUnlock();
}