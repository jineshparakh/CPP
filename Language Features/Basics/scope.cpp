#include <iostream>

int main()
{

    // Everything in C++ is bound to {} scope (except globals).
    // x defined in {} is not accessible outside the scope.
    {
        int x = 42;
    }

    // inaccessible
    // std::cout<<x<<std::endl;

    {
        // This is different than the previous x
        int x = 33;
    }

    return 0;
}