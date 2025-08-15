#include <iostream>
#include <cstring>

struct State {
    int a;
    int b;
    bool c;
    bool d;
};

int main() {

    /*
        reinterpret_cast is a casting operator used for low-level,
        unsafe type conversions. It allows the reinterpretation of
        the bit pattern of one type as if it were another type,
        without any checks or conversions of the underlying value.

        void ptr casting is an important usecase

    */
    State s{22, 33, true, false};

    char bytePool[sizeof(State)];

    std::memcpy(bytePool, &s, sizeof(State));


    std::cout << *reinterpret_cast<int*>(bytePool) << std::endl;
    std::cout << *reinterpret_cast<int*>(bytePool + sizeof(int)) << std::endl;
    std::cout << *reinterpret_cast<bool*>(bytePool + 2 * sizeof(int)) << std::endl;
    std::cout << *reinterpret_cast<bool*>(bytePool + 2 * sizeof(int) + sizeof(bool)) << std::endl;


    return 0;
}