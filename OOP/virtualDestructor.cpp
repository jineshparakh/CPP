#include<bits/stdc++.h>
using namespace std;
class A {
private:
	int a, b;
public:
	A() {
		cout << "In constructor of A\n";
	}

	/*
		Without virtual destructor of base class,
		B's destructor will never be called.
		It can lead to memory leaks if heap objects are
		allocated
	*/
	virtual ~A() {
		cout << "In destructor of A\n";
	}

	void print() {
		cout << "In class A\n";
	}
};
class B: public A {
private:
	int x, y;
public:

	B() {
		cout << "In constructor of B\n";
	}
	~B() {
		cout << "In destructor of B\n";
	}

	void print() {
		cout << "In class B\n";
	}
};
int main() {
	A* a = new B;
	a->print();
	delete a;
}