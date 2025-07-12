#include<bits/stdc++.h>
using namespace std;


int main() {
	/*
	    --> Exception is any normal behaviour, runtime error
	    --> Using Exception Handling, a programmer can respond and manage RTEs actively


	    try, throw and catch
	        --> Program statements that you want to monitor for exceptions are contained in a try block
	        --> If any exception occurs within the try block, it is thrown using throw
	        --> The exception is caught using catch and then processed

	    IMP Points:
	        1. try and catch will always be together (Both of them have to exist else no one must exist)
	        2. throw can be present independently (It will not cause CE but will cause RTE)
	*/
	try {
		cout << "This will be printed\n";
		// throw 3239;
		throw ("An error occured");
		cout << "This will not be printed\n";
	}
	catch (char const* s) {
		cout << s << endl;
	}
	catch (...) { // ... indicates all types of throw statements are allowed
		cout << "Non-string exception occured\n";
	}
	cout << "This will again be printed\n";
	// throw 20; // Causes RTE

}