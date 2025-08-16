#include <iostream>
#include <future>


// simulates file read bytesLoaded with sleep for read latency
bool bufferedReaderSimulator() {
    size_t bytesLoaded = 0;
    while (bytesLoaded < 200000) {
        std::cout << "Thread loading file...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 5000;
    }

    return true;
}

int main() {

    std::future<bool> asyncBufferedReaderFn = std::async(
        std::launch::async,
        &bufferedReaderSimulator);


    // status of the async task
    std::future_status status;

    while (true) {
        std::cout << "Main thread is running...\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        status = asyncBufferedReaderFn.wait_for(std::chrono::milliseconds(1));
        if (status == std::future_status::ready) {
            std::cout << "Buffered reader read complete...\n";
            break;
        }
    }

    std::cout << "Main program completed\n";

    return 0;
}