#include <iostream>
#include <thread>
#include <vector>

int main() {

    auto lambda = [](int n) {
        std::cout << "Hello from thread, tid: " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed: " << n << std::endl;
    };


    /*
        With jthreads there is no need for explicit join call
        jthread follows RAII and it's destructor does the joining
        call

    */
    std::vector<std::jthread> jthreads; // since C++20
    for (int i = 0; i < 5; i++) {
        jthreads.push_back(std::jthread(lambda, i));
    }

    std::cout << "Hello from main thread" << std::endl;


    return 0;
}