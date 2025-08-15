#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct PrintNum {
    void operator()(int n) {
        std::cout << n << " ";
    }
};

void printNumFunc(int n) {
    std::cout << n << " ";
}

int main() {

    // Ways to print elements of vector
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Way1 - Without lambda
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // Way2 - Anonymous lambda
    std::for_each(
        v.begin(),
        v.end(),
        [](int n) {
        std::cout << n << " ";
    }
    );
    std::cout << std::endl;

    // Way3 - Functor
    std::for_each(
        v.begin(),
        v.end(),
        PrintNum()
    );
    std::cout << std::endl;

    // Way4 - Pass function
    std::for_each(
        v.begin(),
        v.end(),
        printNumFunc
    );
    std::cout << std::endl;

    // Way5 - Named lambda
    auto printLambda = [](int n) {
        std::cout << n << " ";
    };

    std::for_each(
        v.begin(),
        v.end(),
        printLambda
    );
    std::cout << std::endl;

    return 0;
}