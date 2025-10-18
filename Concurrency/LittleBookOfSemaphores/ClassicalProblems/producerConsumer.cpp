#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>
#include <chrono>

class Buffer {
private:
    std::queue<int> buffer;
    std::binary_semaphore bufferMu;

    // 5 is the max capacity of the buffer
    std::counting_semaphore<5> items;

public:
    Buffer(): bufferMu(1), items(0) {

    }

    void produce(int item) {
        bufferMu.acquire();
        buffer.push(item);
        std::cout << "Thread is: " << std::this_thread::get_id() << " produced item: " << item << std::endl;
        bufferMu.release();

        items.release();
    }

    void consume() {
        items.acquire();

        bufferMu.acquire();
        int item = buffer.front();
        buffer.pop();

        std::cout << "Thread id: " << std::this_thread::get_id() << " consumed item: " << item << std::endl;
        bufferMu.release();
    }

};

class Producer {
    Buffer& buf;
public:
    Producer(Buffer& buf): buf(buf) {
    }

    void operator()() {
        for (int i = 0; i < 10; i++) {
            buf.produce(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(160));
        }
    }

};

class Consumer {
    Buffer& buf;
public:
    Consumer(Buffer& buf): buf(buf) {

    }

    void operator()() {
        for (int i = 0; i < 10; i++) {
            buf.consume();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int main() {

    /*
        Event driven programs are good example of producer consumer pattern

        Requirements:
        --> While an item is being added to or removed from the buffer, the buffer is
            in an inconsistent state. Therefore, threads must have exclusive access to
            the buffer.
        --> If a consumer thread arrives while the buffer is empty, it blocks until a
            producer adds a new item.

    */

    Buffer buf;

    Producer p(buf);
    Consumer c(buf);

    std::thread producerThread(p);
    std::thread consumerThread(c);

    producerThread.join();
    consumerThread.join();
}