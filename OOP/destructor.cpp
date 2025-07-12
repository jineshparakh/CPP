#include<bits/stdc++.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point() {
		x = 0, y = 0;
		cout << "Default constructor invoked\n";
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
		cout << "Parametrized constructor invoked\n";
	}
	~Point() {
		cout << "Destructor invoked\n";
	}

};
int main() {
	/*
	    What is a destructor?
	        --> It is an instance member function of a class hence can never be static
	        --> Destructor name is same as class name preceded by ~(pronounced tilde) symbol
	        --> No return type
	        --> No arguments, hence no overloading is possible
	        --> It is invoked implicitly when object is going to get destroyed

	    Use of destructor?
	        --> It should be defined to release resources allocated to an object

	    Some important points:
	        --> If a programmer does not explicitly create a destructor, compiler creates one.
	        --> But if the programmer creates one explicitly, the compiler does not create one.


	*/
	Point p1;
	Point p2(2, 3);
}