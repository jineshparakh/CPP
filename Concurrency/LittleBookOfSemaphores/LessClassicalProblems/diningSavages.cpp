#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

std::binary_semaphore mu(1);
int numServingsLeft = 0;
std::binary_semaphore potFull(0);
std::binary_semaphore potEmpty(0);

const int M = 5;
const int NUM_SAVAGES = 10;
void savageTask(int savageId) {
    while (true) {
        mu.acquire();
        if (numServingsLeft == 0) {
            printf("Savage %d saw no servings left. Alerting cook\n", savageId);
            potEmpty.release();
            potFull.acquire();
        }

        numServingsLeft--;
        mu.release();

        printf("Savage %d eating\n", savageId);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void cookTask() {
    while (true) {
        potEmpty.acquire();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // mu is already acquired. It is safe to update numServingsLeft;
        numServingsLeft = M;

        printf("Cook refiled pot\n");

        potFull.release();
    }
}

int main() {
    /*
        Problem Statement:
            A tribe of savages eats communal dinners from a large pot that
            can hold M servings of stewed missionary. When a savage wants to
            eat, he helps himself from the pot, unless it is empty. If the pot is
            empty, the savage wakes up the cook and then waits until the cook
            has refilled the pot.

    */
    std::vector<std::thread> savages;

    std::thread cook(&cookTask);
    for (int i = 0; i < NUM_SAVAGES; i++) {
        savages.push_back(std::thread(&savageTask, i));
    }

    cook.join();
    for (int i = 0; i < NUM_SAVAGES; i++) {
        savages[i].join();
    }
}