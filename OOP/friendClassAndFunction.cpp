#include<bits/stdc++.h>
using namespace std;

// Predecleration of class B is necessary becuase it is being passed as an argument in function1
class B;

class A {

private:
	int x = 2;

public:
	/*
	    If it is to be used as a friend to some other class, it should be defined after that class's definition
	    and not int class A.
	*/
	void function1(B);
	/*
	    It means that C (to be specific all member functions of C)can access all the private members of A
	*/
	friend class C;
};

class B {

private:
	int x = 0;
	/*
	    This statement implies that function1 from class A is a friend of class B
	    and can access private members of class B
	*/
	friend void A::function1(B);
};

/*
    Definition of the member function from class A which is friend to class B
*/
void A::function1(B b) {
	cout << "In Function 1 of class A\n";
	cout << "Accessing value of x(Private member of B) outside class B: b.x = " << b.x << endl;

}

class C {
    
public:
	void showA(A a) {
		cout << "In showA function of class C\n";
		cout << "Accessing value of x(Private member of A) outside class A: a.x = " << a.x << endl;
	}
};

int main() {
	A a;
	B b;
	C c;

	a.function1(b);
	c.showA(a);

}