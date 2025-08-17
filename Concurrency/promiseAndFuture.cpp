#include <iostream>
#include <future>
#include <thread>

#define ull unsigned long long
int main() {
    /*
        std::promise
            --> Used to set values or expectations
        std::future
            --> Used to get values from promise
            --> Ask promise if value is available
            --> Wait for the promise

    */

    ull start = 0, end = 1900000000;
    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    std::thread t1([&](std::promise<ull>&& oddSum, ull start, ull end) {
        ull odd = 0;
        for (ull i = start; i <= end; i++) {
            if ((i & 1ULL)) {
                odd += i;
            }
        }

        oddSum.set_value(odd);
    }, std::move(oddSum), start, end);

    std::cout << "Waiting for result...\n";
    ull res = oddFuture.get();
    std::cout << "Result: " << res << "\n";

    t1.join();
}