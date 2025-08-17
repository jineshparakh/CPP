#include <iostream>
#include <mutex>
#include <assert.h>

int main() {
    /*
        std::try_lock will try to lock all the lockable objects passed
        in it one by one in given order.

        On success, it returns -1, on failure it returns 0 based
        index of mutex which could not be acquired.
        If it fails to lock all mutexes, it will unlock all the mutexes locked
        previously.
        If call to try_lock results in a exception, unlock is called for all
        locked objects before throwing the exception.

        IMP: try_lock is non blocking lock. IT TRIES TO ACQUIRE A MUTEX, IF COULD
             NOT ACQUIRE THEN RETURN.

    */
    std::mutex m1, m2, m3;

    if (std::try_lock(m1, m2, m3) == -1) {
        std::cout << "All locks acquired\n";
        m1.unlock();
        m2.unlock();
        m3.unlock();
    }


    m2.lock();
    int status = std::try_lock(m1, m2, m3); // m2 cannot be acquired, status = 1
    assert(status == 1);
    m2.unlock();
}