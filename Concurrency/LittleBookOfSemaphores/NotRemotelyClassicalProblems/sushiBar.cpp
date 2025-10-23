#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <memory>

class SushiBar {
public:
    static const int MAX_TABLES = 5;
private:
    std::binary_semaphore mu;
    int numEating, numWaiting;
    bool forceWait;

    std::counting_semaphore<MAX_TABLES> barrier;

public:
    SushiBar(): mu(1), numEating(0), numWaiting(0), forceWait(false), barrier(0) {

    }

    void enter(int id) {
        mu.acquire();
        if (forceWait) {
            printf("Force wait for Customer %d\n", id);
            numWaiting++;
            mu.release();
            barrier.acquire();
            printf("Force wait over for Customer %d\n", id);
        } else {
            numEating++;
            forceWait = (numEating == MAX_TABLES);
            mu.release();
        }
    }

    void leave(int id) {
        mu.acquire();
        numEating--;
        if (numEating == 0) {
            int canAdd = std::min(static_cast<int>(MAX_TABLES), numWaiting);
            numEating = canAdd;
            numWaiting -= canAdd;
            forceWait = (numEating == MAX_TABLES);

            for (int i = 0; i < numEating; i++) {
                barrier.release();
            }
        }
        mu.release();
    }
};

int main() {

    SushiBar s;

    auto customerFn = [&](int id) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10 * (id % 7)));
        printf("Customer %d entering Sushi Bar\n", id);
        s.enter(id);
        printf("Customer %d eating food\n", id);
        std::this_thread::sleep_for(std::chrono::milliseconds(50 + (id % 5) * 30));
        printf("Customer %d is leaving\n", id);
        s.leave(id);
    };

    std::vector<std::thread> customers;

    for (int i = 0; i < 4 * SushiBar::MAX_TABLES; i++) {
        customers.push_back(std::thread(customerFn, i));
    }

    for (auto& customer : customers) {
        customer.join();
    }

    return 0;
}