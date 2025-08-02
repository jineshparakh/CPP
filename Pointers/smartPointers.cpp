#include <iostream>
#include <memory> // imports unique_ptr, shared_ptr, weak_ptr

// some user defined type
class UDT {
public:
    UDT() {
        std::cout << "UDT constructor called" << std::endl;
    }
    ~UDT() {
        std::cout << "UDT destructor called" << std::endl;
    }
};

int main() {

    /*
    Raw pointers allow sharing
    Two main issues:
    1. Allows room for errors like forgetting to deallocate
    2. No strict ownership

    Smart pointers help to address these issues
    */
    int* x = new int[100];
    for (int i = 0; i < 100; i++) {
        *(x + i) = i;
    }

    int* ptr1 = x;

    // A. unique_ptr
    /*
    With unique_ptr:
    1. We cannot share (no copies allowed. no assignment to other unique_ptr)
    2. We do not have to delete. It itself calls the destructor once the
       block scope ends.
    3. Ownership can be transferred to other unique_ptr using move semantics.

    */

    // Unique pointer to UDT
    // Two ways to create one, second one is more commonly used
    std::unique_ptr<UDT> uniqueUdt = std::unique_ptr<UDT>(new UDT);
    std::unique_ptr<UDT> uniqueUdt2 = std::make_unique<UDT>();

    // unique pointer to array / array that is pointed to by 1 unique ptr
    std::unique_ptr<UDT[]> uniqueUdtArray = std::make_unique<UDT[]>(2);
    std::unique_ptr<UDT[]> uniqueUdtArray2 = std::unique_ptr<UDT[]>(new UDT[2]);

    // Transfer ownership using move
    std::unique_ptr<UDT> uniqueUdt3 = std::move(uniqueUdt2);

    // B. shared_ptr
    /*
    As the name suggests shared_ptr can be assigned to/ shared with
    other shared_ptr(s). When the last share of shared_ptr goes out
    of scope the underlying resource is destroyed.

    shared_ptr keeps track of refCnts in control blocks
    Example:

    Resource(R) <--- PtrP1([pointer|pointerToControlBlock])
                <--- PtrP2([pointer|pointerToControlBlock])

    [controlBlock | refCnt=2]

    */

    std::shared_ptr<UDT> sharedUdt = std::shared_ptr<UDT>(new UDT);
    std::shared_ptr<UDT> sharedUdt2 = std::make_shared<UDT>();

    std::shared_ptr<UDT> sharedUdt3 = sharedUdt2;

    // use_count = 1 because there is only 1 reference of sharedUdt
    std::cout << "sharedUdt use_count: " << sharedUdt.use_count() << std::endl;

    // use_count = 2
    std::cout << "sharedUdt2 use_count: " << sharedUdt2.use_count() << std::endl;
    std::cout << "sharedUdt3 use_count: " << sharedUdt3.use_count() << std::endl;

    // C. weak_ptr
    /*
    1. A non-owning smart pointer that can observe a std::shared_ptr
       without affecting its reference count.
    2. Used to break circular dependencies between shared_ptr objects,
       which can lead to memory leaks.
    3. Cannot directly access the managed object; it must be converted
       to a shared_ptr first using the lock() method. If the observed
       shared_ptr no longer exists, lock() returns an empty shared_ptr.

    */

    std::weak_ptr<UDT> weakUdt;
    {
        std::shared_ptr<UDT> sharedUdt4 = std::make_shared<UDT>();
        {
            weakUdt = sharedUdt4;
            // use_count will be 1 and not 2.
            std::cout << "weakUdt use_count: " << weakUdt.use_count() << std::endl;
        }
        // use_count will be 1. weak_ptr is not added as additional refCnt.
        std::cout << "sharedUdt4 use_count: " << sharedUdt4.use_count() << std::endl;
    } // sharedUdt4 expires here

    // The resource allocated with sharedUdt4 has been freed up

    std::cout << "Does weakUdt point to expired resource: " << weakUdt.expired() << std::endl;

    return 0;
}