#include <iostream>
#include <mutex>

// see: OOP/constCorrectness.cpp first

// from cpp reference
class ThreadSafeCounter {
private:
    mutable std::mutex m; // M&M rule: mutex and mutable go hand in hand
    int counter;

public:
    ThreadSafeCounter() {
        counter = 0;
    }
    int getCounterVal() const {
        std::lock_guard<std::mutex> lk(m);
        return counter;
    }
    void incrCounter() {
        std::lock_guard<std::mutex> lk(m);
        counter++;
    }
};

int main() {

    ThreadSafeCounter counter;
    counter.incrCounter();
    counter.incrCounter();

    std::cout << "counterVal: " << counter.getCounterVal() << std::endl;

    return 0;
}