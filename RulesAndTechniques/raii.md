Resource Acquisition is Initialization (RAII) is a C++ programming technique which binds
the lifetime of a resource that must be acquired before use to the lifetime of an object

RAII can be summarized as follows:
1.  encapsulate each resource into a class, where
    * the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done,
    * the destructor releases the resource and never throws exceptions

1. always use the resource via an instance of a RAII-class that either 
    * has automatic storage duration or temporary lifetime itself, or
    * has lifetime that is bounded by the lifetime of an automatic or temporary object. 


Examples:

A) 
``` cpp
/*
    In this example constructor and destructor
    take the responsibility of initializing
    and destructing the heap objects
*/
class Collection {
private:
    int* data;
public:
    Collection() {
        data = new int[10];
    }

    ~Collection() {
        delete[] data;
    }
}

int main() {
    Collection c;
}
```

B)

```cpp

std::mutex m;
 
void bad() {
    m.lock();             // acquire the mutex
    f();                  // if f() throws an exception, the mutex is never released
    if (!everything_ok())
        return;           // early return, the mutex is never released
    m.unlock();           // if bad() reaches this statement, the mutex is released
}
 
void good() {
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok())
        return;                        // early return, the mutex is released
}                                      // if good() returns normally, the mutex is released
```

Move semantics enable the transfer of resources and ownership between objects, inside and outside containers, and across threads, while ensuring resource safety. 