#include <iostream>

template<typename T>
T sum(T arg) {
    return arg;
}

template<typename T, typename... Args>
T sum(T start, Args... args) {
    return start + sum(args...);
}

int main() {

    std::cout << sum(1, 2, 3, 4, 5) << std::endl;

    // Incorrect result
    std::cout << sum(1, 2.3, 3, 4, 5) << std::endl;

    // correct result
    std::cout << sum<double>(1, 2.3, 3, 4, 5) << std::endl;

    // Again incorrect
    std::cout << sum<double>(1, 2, 3.3, 4, 5) << std::endl;

    // correct
    std::cout << sum<double, double>(1, 2, 3.3, 4, 5) << std::endl;





    return 0;
}