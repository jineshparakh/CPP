#include<bits/stdc++.h>
using namespace std;

class A {
public:
	void print() {
		cout << "In print function of class A\n";
	}
	void showData() {
		cout << "In showData function of class A\n";
	}
};

class B: public A {
public:
	void print() { // method overriding
		cout << "In print function of class B\n";
	}
	void showData(int x) { // method hiding
		cout << "In showData function of class B\n";
	}
};

int main() {
	/*
	    Method overriding:
	        --> When you want the same functionalities in your child class but with different functionalities
	        --> The entire function prototype should be same both in child and parent (No difference allowed)

	    Method hiding:
	        --> A function with same name but different arguments in parent and child class

	*/
	B b;
	/*
	    What happens when you do b.print()?
	        --> When this line is written, during compilation it is the duty of the compiler to bind the call
	            to the declaration (Early binding)
	        --> So the compiler searches through the member functions of the caller object and checks for
	            functions named print().
	        --> If it finds a function in class B, it stops the search process and binds the call to that function
	        --> If it does not find, the compiler continues to search it in the parent class and so on
	*/
	b.print();
	b.A::print();

	/*
	    Why does the line below cause a CE?
	        --> During compilation, the compiler starts the process of searching and binding from the
	            caller class (B)
	        --> So in this class it has a function with the name showData but with different arguments.
	        --> If the name matches, the compiler stops searching and that point and the CE is caused
	            due to mismatch of arguments.
	*/
	// b.showData(); Gives CE
	b.showData(1);
	b.A::showData();
}

