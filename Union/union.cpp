#include <iostream>

union U {
    int x;
    short y;
    float z;

    /*
        In C++ unions can have member functions
    */
    void printX() {
        std::cout << "x is: " << x << std::endl;
    }
};


int main() {

    U myUnion;
    /*
        Once this value is set, all 3 x, y & z have the same value 2000
    */
    myUnion.x = 2000;

    // size of the largest datatype present in union U
    std::cout << "sizeof(U): " << sizeof(U) << std::endl;
    myUnion.printX();


    return 0;
}