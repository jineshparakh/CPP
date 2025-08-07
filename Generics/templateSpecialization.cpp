#include <iostream>
#include <cmath>

const float eps = 0.001f;

template<typename T>
bool equal(T a, T b) {
    return (a == b);
}


// specialization for handling floats
template<>
bool equal<float>(float a, float b) {
    return fabs(a - b) < eps;
}

int main() {

    std::cout << equal<int>(2, 3) << std::endl;
    std::cout << equal<int>(2, 2) << std::endl;

    /*
        Without the specific version for floats, this
        equality check fails
    */
    std::cout << equal<float>(1.0 - 0.9999f, 0.0001f) << std::endl;

    return 0;
}