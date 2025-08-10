#include <iostream>

template<typename T = int, size_t size = 10>
class Container {
private:
    T* data;
public:

    Container() {
        data = new T[size];
        std::cout << "size: " << size << std::endl;
    }

    ~Container() {
        delete[] data;
    }

};

int main() {

    Container<int, 5> c1;
    Container<int> c2;

    // int container with default size 10
    // Cannot pass size without type hint
    Container c3;



    return 0;
}