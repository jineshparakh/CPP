#include<bits/stdc++.h>
using namespace std;

int sum(int, int);
int sum(int, int, int);
int main() {

	/*
	In C, we could not have more than one function having the same name
	In C++ we can do so using function overloading

	Function Overloading:
	    --> More than one function with same name and difference in arguments (and they need to follow some rules obviously)
	    --> Compile time polymorphism

	IMP: int sum(int,int);
	     float sum(int,int);
	     This will give error. Type or count of arguments has to be different 

	One of the important tasks of compiler is to bind function call with the actual function definition.
	This is called Early Binding.

	Steps:
	    1. When the compiler reaches a function call line, it checks the function name of the function call.
	    2. All the functions defined in the program with the same name are candidates for being binded.
	    3. Based on some rules it then checks which function to bind
	Rules:
	    1. The compiler tries to find exact match to function call (same number and type of arguments)
	    2. If no match is found, it tries to find match by promotion:
	        char, unsigned char, short --> Promoted to int
	        float --> Promoted to double
	    3. If, no match is found, it tries to find match via standard conversion

	If the function call does not fit in any of the rules, then an error occurs.
	*/
    
	int a = 2, b = 3, c = 5;
	cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl; // Follows rule 1
	cout << "Sum of " << a << ", " << b << " and " << c << " is: " << sum(a, b, c) << endl; // Follows rule 1

	cout << "Sum of 'a' & 'b' is:(Prints sum of ASCII) " << sum('a', 'b') << endl; // Follows rule 2
	cout << "Sum of 1.1 & 2.9 is:(Prints sum of floor values) " << sum(1.1, 2.9) << endl; // Follows rule 3
}

int sum(int x, int y) {
	return x + y;
}
int sum(int x, int y, int z) {
	return x + y + z;
}