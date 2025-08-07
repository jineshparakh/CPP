#include <iostream>

// Similar to std::array
template<typename T, size_t size>
class Container {
private:
    T* data;
public:
    // Each <T, size> class will have it's own
    // s_variable
    static T s_variable;

    Container() {
        data = new T[size];
    }

    ~Container() {
        delete[] data;
    }

};

template<typename T, size_t size>
T Container<T, size>::s_variable = 343;

int main() {

    Container<int, 5> c1;
    Container<float, 2> c2;

    // Different static variable than Container<int, 5>
    Container<float, 5>::s_variable = 555;

    std::cout << Container<int, 5>::s_variable << std::endl;
    std::cout << Container<float, 5>::s_variable << std::endl;


    return 0;
}