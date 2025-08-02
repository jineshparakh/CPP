#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include<string>

class IntArray {

private:
    std::string name;
    int* data;

public:

    // Big 3 from Rule of 3
    /*
        The "Rule of Three" in C++ states that if a class requires a
        user-defined destructor, a user-defined copy constructor, or
        a user-defined copy assignment operator, it almost certainly
        requires all three.

    */
    // A) Constructor
    IntArray(std::string name);

    // B) Destructor
    ~IntArray();

    // C) Copy Constructor & Copy assignment operator
    IntArray(const IntArray& source);

    IntArray& operator=(const IntArray& source);

    // More 2. In total 5. These form Rule of 5

    // D) Move constructor policy
    IntArray(IntArray&& source);

    // E) Move assignment policy
    IntArray& operator=(IntArray&& source);

};

#endif