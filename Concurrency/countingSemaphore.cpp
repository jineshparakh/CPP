#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>  // >=C++20
#include <chrono>

// The number of identical resources available in the pool.
const int NUM_RESOURCES = 3;

// A counting semaphore initialized with the number of available resources.
// It tracks how many resource "permits" are available.
std::counting_semaphore<NUM_RESOURCES> resource_pool(NUM_RESOURCES);

// A task that requires a resource from the pool.
void use_resource(int thread_id) {
    std::cout << "Thread " << thread_id << " waiting for a resource." << std::endl;

    // Acquire a permit from the semaphore. Blocks if no permits are available.
    resource_pool.acquire();

    std::cout << "Thread " << thread_id << " has acquired a resource." << std::endl;

    // Simulate work being done with the resource.
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << thread_id << " releasing the resource." << std::endl;

    // Release the permit back to the semaphore, allowing another waiting thread to proceed.
    resource_pool.release();
}

int main() {
    std::vector<std::thread> threads;
    const int num_threads = 10;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(use_resource, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads have completed." << std::endl;
    return 0;
}
