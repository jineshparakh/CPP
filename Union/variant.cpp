#include <iostream>
#include <variant> // since C++17


int main() {

    /*
        variant is a tagged union

        For the same fields, sizeof(variant) > sizeof(union).
        One of the reasons for this is because of added type safety.

    */
    std::variant<int, short> v;
    v = (int)22;

    std::cout << "get<int>(v): " << get<int>(v) << std::endl;
    /*
        Line below gives runtime error
            ❯ ./a.out
            get<int>(v): 22
            terminate called after throwing an instance of 'std::bad_variant_access'
            what():  std::get: wrong index for variant
            [1]    68061 IOT instruction (core dumped)  ./a.out

        Reason:
            variant v is assigned an int value.
            It does a type safety check to see that we do not access
            both values for the same variant

    */
    // std::cout << "get<short>(v): " << get<short>(v) << std::endl;

    std::variant<int, short> v2;
    v2 = short(33);
    // no issue here as short variant is defined
    std::cout << "get<short>(v2): " << std::get<short>(v2) << std::endl;

    // data types in get_if can only be one of the types in variant definition (int, float here)
    auto attempt = std::get_if<int>(&v2);
    if (attempt != nullptr) {
        std::cout << "[unexpected]: got long long variant. attempt: " << *attempt << std::endl;
    }

    if (auto attempt = std::get_if<short>(&v2)) {
        std::cout << "[expected]: got short variant. attempt: " << *attempt << std::endl;
    }


    return 0;
}