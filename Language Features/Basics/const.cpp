#include <iostream>

int main()
{

    // a fixed value which cannot be changed once initialized
    const float PI = 3.141525;

    // an expression which can be evaluated at compile time
    // and acts like const at runtime
    constexpr int expression = 3 + 5 + 9;

    std::cout << PI << std::endl;
    std::cout << expression << std::endl;

    return 0;
}