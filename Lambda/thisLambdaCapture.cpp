#include <iostream>

struct Counter {
    int counter;

    Counter() {
        counter = 0;
    }

    void incrCounter() {
        // passing "this" as capture variables
        // tells the compiler to allow access of struct/class
        // variables inside lambda
        auto f = [this]() {
            counter++;
        };
        f();
    }
};

int main() {
    Counter c;
    c.incrCounter();

    std::cout << "c.counter: " << c.counter << std::endl;

    return 0;
}