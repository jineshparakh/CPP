#include <iostream>
#include <cassert>

struct ABC {
    short two;
    float one;
    char three;
};

int main() {

    ABC abc;

    // This tells us the alignment size for struct padding
    std::cout << "aligment size of abc:  " << alignof(abc) << std::endl;

    /*
        sizeof(abc) =
        two - 2 bytes
        2 bytes padding
        one - 4 bytes
        three - 1 byte
        3 bytes padding
    */
    assert(sizeof(abc) == 12);

    return 0;
}