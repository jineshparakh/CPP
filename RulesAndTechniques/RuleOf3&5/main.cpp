#include "IntArray.hpp"
#include <vector>

int main() {

    std::vector<IntArray> myArrays;
    myArrays.reserve(10);

    // We can save on array copies using move
    for (int i = 0; i < 10; i++) {
        IntArray temp(std::move(std::to_string(i)));
        myArrays.push_back(std::move(temp));
    }
}