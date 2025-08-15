#include <iostream>
#include <iomanip>
#include <memory>

struct Base {
    int baseData{1};

    Base() {
        baseData = 11;
    }

    virtual ~Base() {

    }

    virtual void Do() {
        std::cout << "Base.Do(): " << baseData << std::endl;
    }
};

struct Derived: Base {
    int derivedData{2};

    Derived() {
        derivedData = 22;
    }

    void Do() {
        std::cout << "Derived.Do(): " << derivedData << std::endl;
    }
};


int main() {

    /*
        static_cast: Converts between types using a combination of
                     implicit and user-defined conversions.
                     More dangerous, works at compile time

        dynamic_cast: Safely converts pointers and references to classes
                      up, down, and sideways along the inheritance hierarchy.
                      More expensive than static_cast

        IMP:
        1. Avoid casts whereever possible.
        2. Prefer dynamic_cast if you have to cast.
    */


    // use -fpermissive compile flag to run and see the conversion
    // int* p = 0xFFFF1234;
    // std::cout << (long)p << std::endl;

    float f{3.14f};
    int castedF = static_cast<int>(f);
    std::cout << "f: " << std::fixed << std::setprecision(2) << f << " , castedF: " << castedF << std::endl;


    Base b;
    Derived d;

    b.Do();
    d.Do();

    // Treat d as Base and call base method
    static_cast<Base>(d).Do();


    // This cannot be done. There is no pre-existing conversion for
    // Base to Derived because Derived is a Base but Base is not Derived
    // static_cast<Derived>(b).Do();


    Base* b2 = new Base;
    Derived* d2 = new Derived;

    b2->Do();
    d2->Do();

    if (dynamic_cast<Derived*>(b2)) {
        std::cout << "INVALID: can treat Base as Derived" << std::endl;
    }

    // Cast derived d2 as base and call base method
    // Helps to check if something is part of hierarchy and
    // can we call parent methods
    if (dynamic_cast<Base*>(d2)) {
        std::cout << "Treating Derived as Base" << std::endl;

        d2->Do();
        d2->Base::Do();
        d2->Derived::Do();

    } else {
        std::cout << "INVALID: cannot treat Derived and Base" << std::endl;
    }


    delete d2;
    delete b2;

    return 0;
}