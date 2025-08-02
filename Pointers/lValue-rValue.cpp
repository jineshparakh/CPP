#include <iostream>
#include <string>

int main() {
    /*
    lvalue - something with a memory location, &(i)
    rvalue - something which is on the right side
             of assignment operator. It does not point
             anywhere.
    */

    // i is lvalue, 10 is rvalue
    // 10 is pure rvalue
    int i = 10;

    /*
    We cannot do 10 = i because,
    1. It's illogical
    2. lvalue is always supposed to be left operand of the assigment
    */

    /*
    lvalue - a, b, c
    rvalue - 1, 2, (a+b)
             (a+b) is expiring rvalue
    */
    int a = 1;
    int b = 2;
    int c = (a + b);

    /*
    lvalue reference - reference to another lvalue (dataType&)
    */
    int j = 10;
    int& ref = j;

    // We cannot do this
    // initial value of reference to non-const must be an lvalueC/C++(461)
    // int& ref2 = 10;

    // This is legit because the compiler
    // does the heavy lifting of binding 10 an lvalue
    // "const" is necessary to have non lvalue references
    const int& ref2 = 10;

    /*
    rvalue reference: reference to another rvalue
    */
    // 10 is rvalue, x is rvalue reference
    int&& x = 10;

    std::cout << "x is: " << x << std::endl;
    std::cout << "&x is: " << &x << std::endl;

    // Understanding why we need rvalue reference
    std::string s1 = "apple";
    std::string s2 = "mango";

    // Say we want to concatenate these.
    // The line below would copy s1 and s2 to
    // a new location s3
    std::string s3 = s1 + s2;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    // With rvalue references we can do
    std::string&& s4 = s1 + s2;

    std::cout << "s4: " << s4 << std::endl;

    // NOTE: s1, s2 are unchanged here.
    // They do change with move semantics
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    return 0;
}