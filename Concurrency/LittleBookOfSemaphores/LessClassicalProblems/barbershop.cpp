#include <iostream>
#include <semaphore>
#include <vector>
#include <thread>


class Barbershop {
public:
    static const int MAX_CUSTOMERS = 10;
private:

    int currentWaitingCustomers;
    std::binary_semaphore mu;

    std::counting_semaphore<MAX_CUSTOMERS> waitingCustomers;

    // used to assign customer to barber
    std::binary_semaphore barber;

    // signals that customer and barber have done their work
    std::binary_semaphore customerDone;
    std::binary_semaphore barberDone;

public:
    Barbershop(): currentWaitingCustomers(0), mu(1), waitingCustomers(0), barber(0), customerDone(0), barberDone(0) {
    }

    void barberLifecycle() {
        while (true) {
            printf("Barber is sleeping...\n");


            waitingCustomers.acquire();

            mu.acquire();
            currentWaitingCustomers--;
            mu.release();

            barber.release();

            // cut hair simulation
            printf(">>> Barber is cutting hair...\n");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("<<< Barber has finished the haircut.\n\n");

            barberDone.release();
            customerDone.acquire();
        }
    }

    void customerLifecycle(int custId) {
        printf("Customer: %d arrived\n", custId);

        mu.acquire();

        // balk simulation
        if (currentWaitingCustomers == MAX_CUSTOMERS) {
            printf("Customer %d had to go back due to full shop\n", custId);
            mu.release();
            return;
        }

        currentWaitingCustomers++;
        mu.release();

        waitingCustomers.release();
        barber.acquire();

        // getCutHair simulation
        printf("Customer %d getting is haircut done\n", custId);

        customerDone.release();
        barberDone.acquire();
    }
};

int main() {
    /*
        Problem Statement:
        A barbershop consists of a waiting room with n chairs, and the
        barber room containing the barber chair. If there are no customers
        to be served, the barber goes to sleep. If a customer enters the
        barbershop and all chairs are occupied, then the customer leaves
        the shop. If the barber is busy, but chairs are available, then the
        customer sits in one of the free chairs. If the barber is asleep, the
        customer wakes up the barber. Write a program to coordinate the
        barber and the customers

        Formally:
        Customer threads should invoke a function named getHairCut.
        If a customer thread arrives when the shop is full, it can invoke balk,
        which does not return.
        The barber thread should invoke cutHair.
        When the barber invokes cutHair there should be exactly one thread
        invoking getHairCut concurrently.
    */

    Barbershop b;

    std::thread barber(&Barbershop::barberLifecycle, &b);

    std::vector<std::thread> customers;

    for (int i = 0; i < 3 * b.MAX_CUSTOMERS; i++) {
        customers.emplace_back([&, i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000));
            printf("customer %d\n", i);
            b.customerLifecycle(i);
        });
    }

    barber.join();
    for (int i = 0; i < 3 * b.MAX_CUSTOMERS; i++) {
        customers[i].join();
    }

}