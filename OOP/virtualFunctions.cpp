#include<bits/stdc++.h>
using namespace std;

// Classes A and B are parent & child classes respectively without using virtual functions
class A {
public:
	void print() {
		cout << "In print function of class A\n";
	}
};

class B: public A {
public:
	void print() {
		cout << "In print function of class B\n";
	}
};

// Classes C and D are parent & child classes respectively  using virtual functions
class C {
public:
    /*
        This virtual keyword tells the compiler that late binding(binding at runtime) should
        take place for this function

		Working concept behind virtual function link:
		https://www.youtube.com/watch?v=Z_FiER8aAqM&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=45&ab_channel=C%2B%2BbySaurabhShuklaSir	
    */
	virtual void print() {
		cout << "In print function of class C\n";
	}
};

class D: public C {
public:
	void print() {
		cout << "In print function of class D\n";
	}
};

int main() {

	/*
	    Base Class Pointer:
	        --> Base class pointer can point to the objects of any of it's descendant class(es)
	        --> The converse is not true (Child pointer can't point to parent's objects)

	    IMP: Binding of function call with function definition happens at Compile Time only
	*/

	cout << "Before using virtual function..\n";
	A *p1, a;
	B b;
	p1 = &b;
	a.print();
	b.print();

	/*
	    The main issue with overriding occurs over here.
	    --> You feel that since p1 contains address of an object of class B, it should bind with the print()
	        method of class B
	    --> However, this does not happen in reality. Binding happens at compile time.
	    --> The function call at this moment does not know the address it will contain. Cause addresses are
	        assigned at runtime
	    --> So it checks for the datatype of p1 which is of type A and binds it there
	    --> Thus, print() function of class A is called

	    This problem in hand paves way for the need of virtual function
	*/

	p1->print();



	// Using virtual functions
	cout << "\nAfter using virtual function..\n";
	C *p2, c;
	D d;
	p2 = &d;
	c.print();
	d.print();
	p2->print();

}