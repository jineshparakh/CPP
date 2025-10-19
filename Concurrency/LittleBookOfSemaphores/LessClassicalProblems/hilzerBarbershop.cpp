#include <iostream>
#include <semaphore>
#include <queue>
#include <vector>
#include <thread>

class Customer {
private:
    int custId;

public:
    std::binary_semaphore acquireMu;
    std::binary_semaphore paymentMu;
    std::binary_semaphore haircutDoneMu;

    Customer(int custId): custId(custId), acquireMu(0), paymentMu(0), haircutDoneMu(0) {

    }

    void enterShop() {
        printf("Customer %d entering shop\n", custId);
    }

    void sitOnSofa() {
        printf("Customer %d sitting on sofa\n", custId);
    }

    void getHairCut() {
        printf("Customer %d requesting hair cut\n", custId);
    }

    void pay() {
        printf("Customer %d waiting to pay\n", custId);
    }

    void couldNotAccommodate() {
        printf("Customer %d left due to no space\n", custId);
    }

    int getId() {
        return custId;
    }
};

class Barber {
private:
    int barberId;

public:
    Barber(int barberId): barberId(barberId) {

    }

    void sleep() {
        printf("Barber %d is sleeping\n", barberId);
    }

    void cutHair(Customer* c) {
        printf("Barber %d starting haircut for Customer %d\n", barberId, c->getId());
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        printf("Barber %d done haircut for Customer %d\n", barberId, c->getId());
    }

    void acceptPayment(Customer* c) {
        printf("Barber %d accepting payment from Customer %d\n", barberId, c->getId());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        printf("Barber %d done accepting payment from Customer %d\n", barberId, c->getId());
    }
};

class Barbershop {
public:
    static const int MAX_CUSTOMERS_ON_SOFA = 4;
    static const int MAX_CUSTOMERS = 20;

private:
    int currentCustomersOnSofa;
    int currentCustomersStanding;
    std::binary_semaphore arrivalMu;

    std::queue<Customer*> sofaQueue;
    std::queue<Customer*> standingQueue;
    std::queue<Customer*> paymentQueue;

    std::vector<std::thread> barberThreads;

    std::counting_semaphore<MAX_CUSTOMERS> customersArrived;
    std::counting_semaphore<MAX_CUSTOMERS> customersWaitingForPayment;

public:

    void registerBarber(Barber* b) {
        while (true) {
            b->sleep();

            customersArrived.acquire();

            arrivalMu.acquire();
            rebalanceQueues();

            Customer* custToServe = sofaQueue.front();
            sofaQueue.pop();
            currentCustomersOnSofa--;

            arrivalMu.release();


            custToServe->acquireMu.acquire();
            b->cutHair(custToServe);
            custToServe->haircutDoneMu.release();

            arrivalMu.acquire();
            paymentQueue.push(custToServe);
            customersWaitingForPayment.release();
            arrivalMu.release();


            customersWaitingForPayment.acquire();
            arrivalMu.acquire();
            Customer* paymentCustomer = paymentQueue.front();
            paymentQueue.pop();
            arrivalMu.release();


            paymentCustomer->paymentMu.acquire();
            b->acceptPayment(paymentCustomer);
        }
    }

    Barbershop(std::vector<Barber*>& barbers): currentCustomersOnSofa(0), currentCustomersStanding(0), arrivalMu(1), customersArrived(0), customersWaitingForPayment(0) {
        for (int i = 0; i < int(barbers.size()); i++) {
            barberThreads.push_back(std::thread(&Barbershop::registerBarber, this, barbers[i]));
        }
    }

    void customerLifecycle(Customer* cust) {

        arrivalMu.acquire();
        if (currentCustomersOnSofa + currentCustomersStanding == MAX_CUSTOMERS) {
            cust->couldNotAccommodate();
            arrivalMu.release();
        }

        standingQueue.push(cust);
        currentCustomersStanding++;
        cust->enterShop();

        if (currentCustomersOnSofa < MAX_CUSTOMERS_ON_SOFA) {
            Customer* longestStandingCustomer = standingQueue.front();
            standingQueue.pop();
            currentCustomersStanding--;

            currentCustomersOnSofa++;
            sofaQueue.push(longestStandingCustomer);

            longestStandingCustomer->sitOnSofa();
        }

        arrivalMu.release();

        customersArrived.release();

        cust->getHairCut();
        cust->acquireMu.release();

        cust->haircutDoneMu.acquire();

        cust->pay();
        cust->paymentMu.release();
    }

    // arrivaMu should be acquired before calling
    void rebalanceQueues() {
        while (currentCustomersOnSofa < MAX_CUSTOMERS_ON_SOFA && currentCustomersStanding>0) {
            currentCustomersStanding--;
            Customer* longestStandingCust = standingQueue.front();
            standingQueue.pop();

            currentCustomersOnSofa++;
            sofaQueue.push(longestStandingCust);
            longestStandingCust->sitOnSofa();

        }
    }

    ~Barbershop() {
        for (int i = 0; i < int(barberThreads.size()); i++) {
            barberThreads[i].join();
        }
    }
};

int main() {
    /*
        Problem statement:
        Our barbershop has three chairs, three barbers, and a waiting
        area that can accommodate four customers on a sofa and that has
        standing room for additional customers. Fire codes limit the total
        number of customers in the shop to 20.
        A customer will not enter the shop if it is filled to capacity with
        other customers. Once inside, the customer takes a seat on the sofa
        or stands if the sofa is filled. When a barber is free, the customer
        that has been on the sofa the longest is served and, if there are any
        standing customers, the one that has been in the shop the longest
        takes a seat on the sofa. When a customer’s haircut is finished,
        any barber can accept payment, but because there is only one cash
        register, payment is accepted for one customer at a time. The bar-
        bers divide their time among cutting hair, accepting payment, and
        sleeping in their chair waiting for a customer.

        Formally:
        1. Customers invoke the following functions in order: enterShop, sitOnSofa, getHairCut, pay.
        2. Barbers invoke cutHair and acceptPayment.
        3. Customers cannot invoke enterShop if the shop is at capacity.
        4. If the sofa is full, an arriving customer cannot invoke sitOnSofa.
        5. When a customer invokes getHairCut there should be a corresponding
        barber executing cutHair concurrently, and vice versa.
        6. It should be possible for up to three customers to execute getHairCut
        concurrently, and up to three barbers to execute cutHair concurrently.
        7. The customer has to pay before the barber can acceptPayment.
        8. The barber must acceptPayment before the customer can exit

    */
    std::vector<Barber*> barbers;

    for (int i = 0; i < 3; i++) {
        Barber* b = new Barber(i);
        barbers.push_back(b);
    }

    Barbershop b(barbers);

    std::vector<std::thread> customers;

    for (int i = 0; i < 20; i++) {
        Customer* cust = new Customer(i);
        customers.push_back(std::thread(&Barbershop::customerLifecycle, &b, cust));
    }

    for (int i = 0; i < 20; i++) {
        customers[i].join();
    }
}

