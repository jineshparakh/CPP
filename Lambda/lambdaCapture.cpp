#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


int globalV = 1000;

int main() {

    // Find max element from vector
    std::vector<int> v = {1, 2, 3, 4, 5};

    int maxx = INT_MIN;

    // [] brackets should have variables that need
    // to be captured
    // -> void is trailing return type
    auto maxFinder = [&maxx](int n) -> void {
        maxx = std::max(maxx, n);
    };
    std::for_each(
        v.begin(),
        v.end(),
        maxFinder
    );

    std::cout << "Max(v) via maxFinder is: " << maxx << std::endl;

    maxx = INT_MIN;
    /*
        NON-EXPLICIT capture variables

        If & is specified in capture part,
        compiler is smart enough to find the
        variables defined outside and use them
    */
    auto maxFinder2 = [&](int n) {
        maxx = std::max(maxx, n);
    };
    std::for_each(
        v.begin(),
        v.end(),
        maxFinder2
    );
    std::cout << "Max(v) via maxFinder2 is: " << maxx << std::endl;


    // Lambdas and global variables

    // = is short for pass by value
    // globals, static can still be modified without mutable keyword
    auto loop = [=](int n) {
        globalV = n;
    };

    std::cout << "globalV before loop: " << globalV << std::endl;

    std::for_each(
        v.begin(),
        v.end(),
        loop
    );

    std::cout << "globalV after loop: " << globalV << std::endl;

    return 0;
}