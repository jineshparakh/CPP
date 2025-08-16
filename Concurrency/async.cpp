#include <iostream>
#include <future>

int square(int x) {
    return x * x;
}

int main() {
    /*
        std::async - without synchronization
        async means I will not be blocked on that thread,
        it can be executed in the background with the option
        to wait for the result
    */

    // "If no launch policy is specified, the implementation may choose to
    // run the task immediately in the current thread (deferred), or it may
    // start it asynchronously on a new thread (async), or a combination." 
    std::future<int> asyncFn = std::async(std::launch::async, &square, 15);


    // We are blocked at "get" until our asyncFn
    // result has been computed
    int res = asyncFn.get();
    std::cout << "res: " << res << std::endl;


    return 0;
}