#include<bits/stdc++.h>
using namespace std;

// Function Declaration
void globalFunction(); // can be called anywhere in the program
int main() {
	/*
	What is a function?
	    --> Block of code performing a task (Helps in achieving modularization)
	    --> Syntax:
	            returnType name(arguements){

	            }
	    --> Types:
	            1. Pre-defined(Declared in header files and defined in library files)
	            2. User-defined
		--> Benefits:
				1. Easy to Read & Modify
				2. Avoid duplication of code
				3. Easy to debug codes
				4. Better memory utilization (Only the functions in use are present in RAM)
	*/
	void localFunction(); // Can be only called in main method
    cout<<"Calling localFunction() from main: ";
	localFunction(); // Function call
	globalFunction();
}

// Function Definitions
void globalFunction() {
	cout << "In Global Function\n";
	/*
	Un-commenting the line below gives the following error
	 ‘localFunction’ was not declared in this scope; did you mean ‘globalFunction’?

	*/
	// localFunction();
}
void localFunction() {
	cout << "In Local Function\n";
	cout << "Calling globalFunction() from localFunction():\n";
	globalFunction(); // A global function can be called from a local function but vice versa might not be possible
}
