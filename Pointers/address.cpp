#include <iostream>

int main() {
    int a = 1;
    float b = 3.14;
    char c = 'c';
    signed char d = 'd';
    unsigned char e = 'e';

    // Prints hex address
    std::cout << "&a: " << &a << std::endl;
    std::cout << "&b: " << &b << std::endl;

    // Simply printing &c, &d, &e does not
    // give the variable address
    // This prints "cde"
    // Why?
    // When you print &c, it keeps printing
    // all contiguous memory blocks until it finds
    // a \n.
    // So for &d, it will print "de"
    std::cout << "&c: " << &c << std::endl;

    std::cout << "(void*)&c: " << (void*)&c << std::endl;

    std::cout << "(void*)&d: " << (void*)&d << std::endl;
    std::cout << "(void*)&e: " << (void*)&e << std::endl;

    // function address
    std::cout << "(void*)&main: " << (void*)&main << std::endl;

    // references

    int x = 42;

    // int& is the data type for reference
    int& ref = x;

    std::cout << "x: " << x << std::endl; // 42
    std::cout << "&x: " << &x << std::endl;
    std::cout << "ref: " << ref << std::endl; // 42
    std::cout << "&ref: " << &ref << std::endl;

    return 0;
}