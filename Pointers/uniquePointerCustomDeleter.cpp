#include <iostream>
#include <memory>

struct IntDeleter {
    void operator()(int* intPtr) {
        std::cout << "IntDeleter called\n";
        delete intPtr;
    }
};

int main() {

    std::unique_ptr<int> uniquePtr(new int);
    std::unique_ptr<int> uniquePtr2 = std::make_unique<int>();

    // Custom deleter
    // make_unique syntax does not work here
    std::unique_ptr<int, IntDeleter> uniquePtr3(new int);



    return 0;
}