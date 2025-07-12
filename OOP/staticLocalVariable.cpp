#include<bits/stdc++.h>
using namespace std;

void foo() {
	static int x;
	x++;
	cout << x << endl;
}
int main() {
	/*
	    Static local variables:
	        --> Concept is taken from C
	        --> By default initialized to 0 and not some garbage value
	        --> Only one copy is present throughout the lifecycle of the program
	        --> Can be used to implement co-routines in C/C++
	*/
	for (int i = 0; i < 5; i++) {
		foo();
	}

}