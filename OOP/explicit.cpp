#include <iostream>
#include <cassert>

class UDT {
private:
    int data;
public:
    UDT(int x) {
        this->data = x;
    }

    int getData() {
        return this->data;
    }
};

class UDT2 {
private:
    int data;
public:
    explicit UDT2(int x) {
        this->data = x;
    }
    int getData() {
        return this->data;
    }
};

int main() {

    UDT u1 = 500;
    UDT u2 = 500.234f;

    // Without the use of explicit keyword, constructor typecasts
    // 500.234f to int and hence both u1 & u2 have equal values
    assert(u1.getData() == u2.getData() && u2.getData() == 500);



    // no suitable constructor exists to convert from "int" to "UDT2"C/C++(415)
    // With explicit keyword, this initialization is not allowed
    // UDT2 u = 500;

    UDT2 u3{500};

    /*
    This gives narrowing conversion error
        explicit.cpp:40:21: error: narrowing conversion of ‘5.00234009e+2f’ from ‘float’ to ‘int’ [-Wnarrowing]
        UDT2 u4{500.234f};

    */
    // UDT2 u4{500.234f};

    return 0;
}