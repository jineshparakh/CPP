#include <iostream>

class UDT {

private:
    int data;

public:
    UDT() {

    }

    ~UDT() {

    }

    void setData(int x) {
        data = x;
    }

    void foo() {
        data = 222;
    }

    /*
        Say in this example we do not want
        to modify data while calling getData
        but there are some other calls which can
        indirectly modify data and cause us return incorrect
        values.
        Example: function foo in this case modifies data to 222
                 and hence we return wrong values

        const keyword is used to protect such adverse effects.
        It tells that during course of getData() runtime, there
        should be no modifications to data;

    */
    int getData() const {
        // foo();
        return data;
    }
};

int main() {

    UDT u;
    u.setData(100);
    std::cout << u.getData() << std::endl;


    return 0;
}