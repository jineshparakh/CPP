#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <iomanip>

class StringPrinter {
private:
    std::vector<std::thread> threads;
    std::vector<std::thread::id> threadIds;
    int batchSize;
    int maxLoops;
    int threadCount;
    std::string s;

    std::mutex mu;
    std::condition_variable cv;

    int currIdx;
    int currThreadIdx;
    bool canPrint;

public:
    StringPrinter(std::string& s, int threadCount, int batchSize, int maxLoops) {
        mu.lock();
        {
            this->s = std::move(s);
            this->batchSize = batchSize;
            this->maxLoops = maxLoops;
            this->threadCount = threadCount;
            this->currIdx = 0;
            this->currThreadIdx = 0;
            this->canPrint = true;


            for (int i = 0; i < threadCount; i++) {
                std::thread t(&StringPrinter::printer, this);
                threadIds.push_back(t.get_id());
                threads.push_back(std::move(t));

            }
        }
        mu.unlock();
    }

    ~StringPrinter() {
        for (int i = 0; i < threadCount; i++) {
            threads[i].join();
        }
    }

    void printer() {
        while (1) {
            std::unique_lock<std::mutex> lock(mu);
            cv.wait(lock, [&]() {
                return static_cast<int>(threadIds.size()) > currThreadIdx &&
                    std::this_thread::get_id() == threadIds[currThreadIdx];
            });

            if (!canPrint) {
                std::cout << "Thread T" << currThreadIdx << " stopped\n";
                currThreadIdx = (currThreadIdx + 1) % threadCount;
                cv.notify_all();

                return;
            }

            std::cout << "Printing s via T" << currThreadIdx << ": ";
            for (int i = 0; i < batchSize; i++) {
                int curr = (currIdx + i) % s.size();
                std::cout << s[curr];
            }
            std::cout << std::endl;

            int newIdx = (currIdx + batchSize) % s.size();
            if (newIdx <= currIdx) {
                maxLoops--;
            }
            if (maxLoops <= 0) {
                canPrint = false;
            }

            currThreadIdx = (currThreadIdx + 1) % threadCount;
            currIdx = newIdx;

            cv.notify_all();
        }
    }
};

int main() {

    /*
        Problem:
        Given a string s, int n(num chars) and int tc(thread count) and K.
        You need to print n consecutive chars from s in 1 thread.
        Loop for K times max

        Example:
        s=abcde
        n=2
        tc=3

        t0=ab
        t1=cd
        t2=ea
        t0=bc
        t1=de
        ....
    */

    std::string s;
    int tc; int n; int k;
    std::cin >> s >> tc >> n >> k;

    StringPrinter stringPrinter(s, tc, n, k);

}