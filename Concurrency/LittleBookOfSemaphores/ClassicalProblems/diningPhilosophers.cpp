#include <iostream>
#include <vector>
#include <semaphore>
#include <memory>
#include <thread>
#include <functional> // Required for std::function
#include <random>

class DiningPhilosophers {
public:
    static const int MAX_PHILOSOPHERS = 5;

private:
    std::vector<std::unique_ptr<std::binary_semaphore>> forkMu;
    // Allow at most MAX_PHILOSOPHERS-1 philosophers to enter concurrently to prevent deadlock
    // This also prevents starvation at any point only MAX_PHILOSOPHERS-1 unique philosophers
    // can hold forks ==> at least 1 philosopher will have both forks. The next time it comes
    // again, it's neighbor will already have 1 fork in hand ==> Same philosopher cannot acquire
    // both forks more than once consecutively. 
    std::counting_semaphore<MAX_PHILOSOPHERS - 1> maxUniqueEntrants;

public:

    DiningPhilosophers(): maxUniqueEntrants(MAX_PHILOSOPHERS - 1) {
        for (int i = 0; i < MAX_PHILOSOPHERS; i++) {
            forkMu.push_back(std::make_unique<std::binary_semaphore>(1));
        }
    }

    int rightFork(int i) {
        return i;
    }

    int leftFork(int i) {
        return (i + 1) % MAX_PHILOSOPHERS;
    }

    void wantsToEat(int i,
        std::function<void()> pickLeftFork,
        std::function<void()> pickRightFork,
        std::function<void()> eat,
        std::function<void()> putLeftFork,
        std::function<void()> putRightFork) {

        printf("Philosopher %d is thinking.\n", i);

        // Acquire a spot at the table
        maxUniqueEntrants.acquire();
        printf("Philosopher %d is hungry and sits at the table.\n", i);

        // Acquire forks
        forkMu[leftFork(i)]->acquire();
        pickLeftFork();
        forkMu[rightFork(i)]->acquire();
        pickRightFork();

        // Eat
        eat();

        // Release forks
        putRightFork();
        forkMu[rightFork(i)]->release();
        putLeftFork();
        forkMu[leftFork(i)]->release();

        // Leave the table
        maxUniqueEntrants.release();

        printf("Philosopher %d finished eating and leaves the table.\n", i);
    }
};

// This function defines the actions for a single philosopher thread
void philosopher_thread(int id, DiningPhilosophers& dp) {
    // Define the lambda functions to be passed to wantsToEat
    auto pickLeftFork = [id]() { printf("Philosopher %d picked up their left fork.\n", id); };
    auto pickRightFork = [id]() { printf("Philosopher %d picked up their right fork.\n", id); };
    auto eat = [id]() {
        printf(">>> Philosopher %d is eating.\n", id);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    };
    auto putLeftFork = [id]() { printf("Philosopher %d put down their left fork.\n", id); };
    auto putRightFork = [id]() { printf("Philosopher %d put down their right fork.\n", id); };

    // Call the main method with the implemented functions
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 20));
    dp.wantsToEat(id, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);

}

int main() {

    /*
        Requirement:
        1. Only one philosopher can hold a fork at a time.
        2. It must be impossible for a deadlock to occur.
        3. It must be impossible for a philosopher to starve waiting for a fork.
        4. It must be possible for more than one philosopher to eat at the same time


        Constraints:
        There are 5 philosophers sitting in a circle with 5 forks between them

    */
    DiningPhilosophers dining_philosophers;
    std::vector<std::thread> philosophers;

    // Create and launch MAX_PHILOSOPHERS philosopher threads
    for (int i = 0; i < DiningPhilosophers::MAX_PHILOSOPHERS; ++i) {
        philosophers.emplace_back(philosopher_thread, i, std::ref(dining_philosophers));
    }

    for (auto& t : philosophers) {
        t.join();
    }

    return 0;
}
