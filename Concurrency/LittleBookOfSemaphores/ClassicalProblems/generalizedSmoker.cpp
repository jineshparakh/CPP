#include <iostream>
#include <thread>
#include <functional>


// std::binary_semaphore agentSem(1);
std::binary_semaphore releaseTobacco(0);
std::binary_semaphore releasePaper(0);
std::binary_semaphore releaseMatch(0);

std::binary_semaphore mu(1);
int numPapers = 0, numTobacco = 0, numMatch = 0;

std::binary_semaphore hasTobacco(0);
std::binary_semaphore hasPaper(0);
std::binary_semaphore hasMatch(0);

void agentTask(int agentId, std::function<void()> fn) {
    while (true) {
        // agentSem.acquire();
        printf("Agent %d releasing ingredients\n", agentId);
        fn();
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
}

void pusherTask(int pusherId, std::function<void()> fn) {
    while (true) {
        fn();
    }
}

void smokerTask(int smokerId, std::function<void()> fn) {
    while (true) {
        fn();
    }
}


// TODO: Remove duplication
int main() {
    std::vector<std::thread> agents;
    std::vector<std::thread> pushers;
    std::vector<std::thread> smokers;

    auto agent0Fn = []() {
        releaseTobacco.release();
        releasePaper.release();
        printf("Agent 0 released tobacco and paper\n");

    };

    auto agent1Fn = []() {
        releasePaper.release();
        releaseMatch.release();
        printf("Agent 1 released paper and match\n");

    };

    auto agent2Fn = []() {
        releaseTobacco.release();
        releaseMatch.release();
        printf("Agent 0 released tobacco and match\n");

    };
    agents.push_back(std::thread(&agentTask, 0, agent0Fn));
    agents.push_back(std::thread(&agentTask, 1, agent1Fn));
    agents.push_back(std::thread(&agentTask, 2, agent2Fn));


    auto pusher0Fn = []() {
        releaseTobacco.acquire();
        mu.acquire();
        if (numPapers > 0) {
            numPapers--;
            printf("Pusher 0 releasing tobacco and paper to smoker 2\n");
            hasMatch.release();
        } else if (numMatch > 0) {
            numMatch--;
            printf("Pusher 0 releasing tobacco and match to smoker 1\n");
            hasPaper.release();
        } else {
            numTobacco++;
        }
        mu.release();
    };

    auto pusher1Fn = []() {
        releasePaper.acquire();
        mu.acquire();
        if (numTobacco > 0) {
            numTobacco--;
            printf("Pusher 1 releasing paper and tobacco to smoker 2\n");
            hasMatch.release();
        } else if (numMatch > 0) {
            numMatch--;
            printf("Pusher 1 releasing paper and match to smoker 0\n");
            hasTobacco.release();
        } else {
            numPapers++;
        }
        mu.release();
    };

    auto pusher2Fn = []() {
        releaseMatch.acquire();
        mu.acquire();
        if (numTobacco > 0) {
            numTobacco--;
            printf("Pusher 2 releasing match and tobacco to smoker 1\n");

            hasPaper.release();
        } else if (numPapers > 0) {
            numPapers--;
            printf("Pusher 2 releasing match and paper to smoker 0\n");
            hasTobacco.release();
        } else {
            numMatch++;
        }
        mu.release();
    };

    pushers.push_back(std::thread(&pusherTask, 0, pusher0Fn));
    pushers.push_back(std::thread(&pusherTask, 1, pusher1Fn));
    pushers.push_back(std::thread(&pusherTask, 2, pusher2Fn));


    auto smoker0Fn = []() {
        hasTobacco.acquire();
        // agentSem.release();

        printf("Smoker %d has tobacco & smoking\n\n\n", 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    };

    auto smoker1Fn = []() {
        hasPaper.acquire();
        // agentSem.release();

        printf("Smoker %d has paper & smoking\n\n\n", 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    };

    auto smoker2Fn = []() {
        hasMatch.acquire();
        // agentSem.release();

        printf("Smoker %d has match & smoking\n\n\n", 2);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    };

    smokers.push_back(std::thread(&smokerTask, 0, smoker0Fn));
    smokers.push_back(std::thread(&smokerTask, 1, smoker1Fn));
    smokers.push_back(std::thread(&smokerTask, 2, smoker2Fn));


    for (int i = 0; i < 3; i++) {
        pushers[i].join();
        smokers[i].join();
    }

    for (int i = 0; i < 3; i++) {
        agents[i].join();
    }

}
