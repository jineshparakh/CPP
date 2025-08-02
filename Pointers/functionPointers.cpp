#include <functional>
#include <iostream>

// This is a type definition for a function pointer
// with signature int func(int, int)
typedef int (*funcPtrIntegerOperations)(int, int);

int add(const int a, const int b) {
    return a + b;
}

int multiply(const int a, const int b) {
    return a * b;
}

int main() {
    // Without function pointers
    std::cout << "add(2, 3): " << add(2, 3) << std::endl;
    std::cout << "multiply(2, 3): " << multiply(2, 3) << std::endl;

    // With function pointers

    // function pointer for function with signature int func(int, int)
    int (*ptr)(int, int);

    ptr = add;
    std::cout << "ptr: add(2, 3): " << ptr(2, 3) << std::endl;

    ptr = multiply;
    std::cout << "ptr: multiply(2, 3): " << ptr(2, 3) << std::endl;

    // using typedefs

    funcPtrIntegerOperations ptrOp;

    ptrOp = add;
    std::cout << "ptrOp: add(2, 3): " << ptrOp(2, 3) << std::endl;

    ptrOp = multiply;
    std::cout << "ptrOp: multiply(2, 3): " << ptrOp(2, 3) << std::endl;

    // using std functions
    std::function<int(int, int)> op;

    op = add;
    std::cout << "op: add(2, 3): " << op(2, 3) << std::endl;

    op = multiply;
    std::cout << "op: multiply(2, 3): " << op(2, 3) << std::endl;

    return 0;
}