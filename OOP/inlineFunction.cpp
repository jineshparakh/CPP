#include<bits/stdc++.h>
using namespace std;

inline int square(int x);
int main() {
	/*
	What is the need of inline function?
	    --> Every time a function is called, it takes some time in context switching by saving previous states,
	        jumping to next state and saving things into registers and pushing them onto a stack.
	    --> So for small functions, the memory utlization is less when compared to the extra time trade off
	To eliminate these drawbacks, inline functions are created.

	Inline Function:
	    --> It is expanded in line when the function is called
	    --> Compiler replaces the function call with the function code present in the inline function

	IMP: Inline is a request not a command
	--> Compiler gets to decide based on memory usage whether to accept a function as inline or treat it as
	    a normal function
	--> If function has loops, switch, goto, recursion, static variables, etc compiler does not accept it as inline.
	*/
	int a = 5;
	int sq = square(a);
	cout << "Square of " << a << " is: " << sq << endl;
}
int square(int x) {
	return x * x;
}