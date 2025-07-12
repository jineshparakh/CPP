#include<bits/stdc++.h>
using namespace std;

class A {

public:
	A() {
		cout << "In the default constructor of parent A\n";
	}
	~A() {
		cout << "In the destructor of parent A\n";
	}
};
class B: public A {

public:
	B() {
		cout << "In the default constructor of parent B\n";
	}
	~B() {
		cout << "In the destructor of child B\n";
	}
};
class C {

private:
	int x;

public:
	C(int x) {
		cout << "Assigned the value of x in Class C. x = " << x << endl;
		this->x = x;
	}
	~C() {
		cout << "In the destructor of parent C\n";
	}
};

class D: public C {

private:
	int y;

public:
	/*
	    Why this weird syntax?
	        --> We have created a paratemetrized constructor in out parent class C.
	            Thus default constructor will not be created by the compiler
	        --> We aim to initialize values of both x and y using the constructors.
	        --> So we will have to pass the value to the constructor of the parent class with
	            which we wish to initialize.
	        --> Thus this syntax

	    What is the exact process followed?
	        1. You create an object of class D, say (2,3)
	        2. The paramterized constructor of D gets called
	        3. Before executing the constructor of D, it calls the parametrized constructor of C i.e C(x)
	        4. One the value of x has been assigned, the value of y gets assigned

	    IMP Point:
	        --> Constructor(s) of the derived classes call the constructor(s) of the base class
	*/
	D(int x, int y): C(x) {
		cout << "Assigned the value of y in Class D. y = " << y << endl;
		this->y = y;
	}
	~D() {
		cout << "In the destructor of child D\n";
	}
};

int main() {

	/*
	Prerequisites:
	    --> If user does not create any constructor for any class, compiler by default creates a default
	        and a copy constructor
	    --> In any class destructor is needed to release the memory allocated to the resources. In a destructor, we can do some
	        final tasks before an object is removed from the memory.

	Order of calling of constructors: From child to parent
	Order of execution of constructors: From parent to child
	Order of calling of destructors: From child to parent
	Order of execution of destructors: From child to parent
	*/

	B b;
	D d(2, 3);
}