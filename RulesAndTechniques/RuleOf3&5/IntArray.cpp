#include "IntArray.hpp"

IntArray::IntArray(std::string name) {
    this->name = name;
    this->data = new int[10];
}

IntArray:: ~IntArray() {
    delete[] data;
}

IntArray::IntArray(const IntArray& source) {
    this->name = std::move(source.name);
    this->data = new int[10];

    for (int i = 0; i < 10; i++) {
        this->data[i] = source.data[i];
    }
}

IntArray& IntArray:: operator=(const IntArray& source) {
    if (this != &source) {
        this->name = std::move(source.name);
        delete[] this->data;

        this->data = new int[10];
        for (int i = 0; i < 10; i++) {
            this->data[i] = source.data[i];
        }
    }

    return *this;
}

IntArray::IntArray(IntArray&& source) {
    this->name = std::move(source.name);
    source.name = "";

    this->data = source.data;
    source.data = nullptr;
}

IntArray& IntArray:: operator=(IntArray&& source) {
    if (this != &source) {
        this->name = std::move(source.name);
        source.name = "";

        this->data = source.data;
        source.data = nullptr;
    }

    return *this;
}
