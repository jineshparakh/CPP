#include <iostream>

template<typename T>
class Container {
private:
    T* data;
public:

    Container(int n) {
        data = new T[n];
    }

    ~Container() {
        delete[] data;
    }

};

// Similar to std::array
template<typename T, size_t size>
class Container2 {
private:
    T* data;
public:

    Container2() {
        data = new T[size];
    }

    ~Container2() {
        delete[] data;
    }

};

int main() {

    Container<int> c1(10);
    Container<float> c2(20);


    // Compiler will generate separate classes
    // for c3 and c4 because size is different
    // Everything inside <> should be same for a single class
    Container2<int, 5> c3;
    Container2<int, 6> c4;

    Container2<double, 5> c5;

    return 0;
}