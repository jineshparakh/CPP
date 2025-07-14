#include <array>
#include <iostream>
#include <iterator>
#include <numeric>

int main()
{

    std::array<int, 10> arr;
    // same as int arr[10];

    // iota comes from numeric header
    // std::begin, std::end come from iterator header
    std::iota(std::begin(arr), std::end(arr), 10);

    // check for bounds and set index 5 to 1000
    arr.at(5) = 1000;

    return 0;
}