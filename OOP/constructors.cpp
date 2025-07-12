#include<bits/stdc++.h>
using namespace std;

class Point {

private:

	int x, y;

public:

	Point() { // Default Constructor
		x = 0, y = 0;
	}

	Point(int k) {  // Parameterized Constructor
		x = k, y = k;
	}

	Point(int x, int y) {   // Parameterized Constructor
		this->x = x;
		this->y = y;
	}

	Point(Point &p) {   // Copy Constructor
		this->x = p.x;
		this->y = p.y;
	}
};

int main() {
	/*
	    What is a constructor?
	        --> The work of constructor is to make an object an object (Tough to understand statement:) )
	        --> Instance Member function of class (Hence, can never be static)
	        --> Name of constructor is same as class name
	        --> Cannot use return keyword
	        --> It is implicitely invoked when an object is created
	        --> Used to solve the problem of intialization of member variables
            --> If any object is created, a constructor has to be invoked (No questions asked it has to be invoked)

	    Some important points:
	        --> By default when a programmer does not create any constructor by ownself, the compiler creates
	            a default constructor and a copy constructor
	        --> When a programmer creates a copy constructor by ownself, the compiler does not create any constructors
	        --> When a programmer creates a default constructor by ownself, the compiler creates a copy constructor

	    Some things wrt Copy Constructor:

	        Don't you feel the syntax for copy constructor would be more intutive if it were:
	            ClassName (Classname Object){
	                // Copy stuff
	            }
	        But why an additional & sign is needed before the object?

	        So, if the syntax were without the & sign, Clasname Object would call the copy constructor recursively for
	        copying the actual arguments
	        Thus, a reference is passed

	*/
	// Different ways of using constructors to initialize an object

	Point p1;
	Point p2(1, 2);
	Point p3(1);
	/*
	    The p4 declaration gives CE only when user defines a copy constructor by ownself. If no explicit copy
	    constructor is present the below line is syntactically and logically correct
	*/
	// Point p4 = 1;
	Point p5 = p3;
	Point p6(p3);
}
