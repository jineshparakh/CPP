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

// Say UDT2 only allows update on x
class UDT2 {
private:
    mutable int x;
    int y;

public:
    UDT2(int x, int y): x(x), y(y) {
    }

    /*
        --> const towards the tail protects us from
            mutating any value.
        --> mutable keyword associated with x helps
                us mutate x inside updateX.
        --> mutable overrides const
        --> y cannot be changed here
    */
    void updateX(int newX) const {
        x = newX;
        // y = newX; // expression must be a modifiable lvalueC/C++(137)
    }

    void print() {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

int main() {

    UDT u;
    u.setData(100);
    std::cout << u.getData() << std::endl;

    UDT2 u2(10, 20);
    u2.print();
    u2.updateX(20);
    u2.print();

    return 0;
}