#include<bits/stdc++.h>
using namespace std;
class A {
private:
	int a, b;
public:
	void print() {
		cout << "In class A\n";
	}
	virtual ~A() {
		cout << "In destructor of A\n";
	}
};
class B: public A {
private:
	int x, y;
public:
	void print() {
		cout << "In class B\n";
	}
	~B() {
		cout << "In destructor of B\n";
	}
};
int main() {
	A* a = new B;
	a->print();
	delete a;
}