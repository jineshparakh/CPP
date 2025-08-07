#include<bits/stdc++.h>
using namespace std;

void foo() {
	// x is valid only within foo scope
	// It cannot be used outside of foo
	static int s_variable;
	s_variable++;
	cout << s_variable << endl;
}
int main() {
	/*
		Static local variables:
			--> Concept is taken from C
			--> Static variables are allocated in the program binary and not stack/heap
				in .bss section
			--> By default initialized to 0 and not some garbage value
			--> Only one copy is present throughout the lifecycle of the program
			--> Can be used to implement co-routines in C/C++

		IMP:
		We can use objdump -t ./a.out to display info from object files

		> objdump -t ./a.out
		0000000000004154 l     O .bss   0000000000000004              _ZZ3foovE10s_variable

		0 tells that s_variable is initialized to 0
	*/
	for (int i = 0; i < 5; i++) {
		foo();
	}

	// identifier "s_variable" is undefinedC/C++(20)
	// std::cout << s_variable << std::endl;
}