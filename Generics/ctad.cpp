#include <iostream>
#include <vector>

template<typename first, typename second>
struct Entry {
    first m_first;
    second m_second;

    Entry(first f, second s): m_first(f), m_second(s) {
    }

};

int main() {


    /*
        Both of these are correct because of CTAD
        CTAD: Class Template Agrument Deduction

        Compiler can automatically deduce the param types
    */
    Entry<int, int> e(2, 3);
    Entry e2(2, 3);


    // Both of these are same
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector v2 = {1, 2, 3, 4, 5};

    // This gives CE. All the args should be of same type
    // to find vector constructor
    // std::vector v2 = {1, 2.22f, 3, 4, 5};

    return 0;
}