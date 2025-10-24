#include <iostream>
#include <semaphore>
#include <cmath>

class SenateBusStation {
public:
    static const int MAX_BOARDERS = 50;
private:
    std::binary_semaphore mu;
    int waitingRiders;

    std::counting_semaphore<INT_MAX> boardSignal;
    std::counting_semaphore<INT_MAX> boarded;

public:
    SenateBusStation(): mu(1), waitingRiders(0), boardSignal(0), boarded(0) {

    }

    void busArrive(int id) {
        printf("Bus %d arrived\n", id);

        mu.acquire();
        int canAccommodate = std::min(static_cast<int>(MAX_BOARDERS), waitingRiders);
        boardSignal.release(canAccommodate);

        for (int i = 0; i < canAccommodate; i++) {
            boarded.acquire();
        }

        waitingRiders -= canAccommodate;
        mu.release();

        printf("Bus %d departing\n", id);
    }

    void riderArrive(int id) {
        printf("Rider %d arrived\n", id);
        mu.acquire();
        waitingRiders++;
        mu.release();

        boardSignal.acquire();
        printf("Rider %d boarding\n", id);
        boarded.release();
    }
};

int main() {
    // TODO: Fill usage
}