#include <iostream>

class BaseClass {
public:
    int x{3}, y{5};
};

class DerivedClass1: public BaseClass {
public:
    int power{7};
};

class DerivedClass2: public BaseClass {
public:
    int power{10};
};

class FinalDerivedClass: public DerivedClass1, public DerivedClass2 {

};

class BaseClass2 {
public:
    int x{3}, y{5};
};

class DerivedClass3: virtual public BaseClass2 {
public:
    int power{7};
};

class DerivedClass4: virtual public BaseClass2 {
public:
    int power{10};
};

class FinalDerivedClass2: public DerivedClass3, public DerivedClass4 {

};

int main() {

    FinalDerivedClass d;

    /*
        These two lines below cause CE.
        "FinalDerivedClass::x" is ambiguousC/C++(266)

        Reason:
        This is a case of diamond inheritance.
        DerivedClass1 and DerivedClass2 both are derived from Base class "INDIVIDUALLY"

        Inheritance structure

        BaseClass       BaseClass
            |               |
        DerivedClass1   DerivedClass2
            \               /
            FinalDerivedClass

        FinalDerivedClass does not know which x to get.
        There are two choices
        DerivedClass1::x
        DerivedClass2::x
    */
    // std::cout << d.x << std::endl;
    // std::cout << d.y << std::endl;
    std::cout << d.DerivedClass1::x << std::endl;
    std::cout << d.DerivedClass1::y << std::endl;

    std::cout << d.DerivedClass2::x << std::endl;
    std::cout << d.DerivedClass2::y << std::endl;

    /*
        This scope resolution can be solved by using virtual
        inheritance.
        NOTE: This type of virtual inheritance can only be used in
        cases where there are more than one derived classes derived
        individually from the same base class.
    */

    FinalDerivedClass2 d2;
    std::cout << d2.x << std::endl;
    std::cout << d2.y << std::endl;
    return 0;
}