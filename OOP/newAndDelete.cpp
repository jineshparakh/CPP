#include<bits/stdc++.h>
using namespace std;

int main() {
	/*
	    SMA: Static Memory Allocation
	    DMA: Dynamic Memory Allocation (Implemented using new and delete in C++)

	    In SMA, the amount of memory allocated to the declaration statements(int x, float y, etc) is decided
	    during Compile time only and cannot be changed. However, the memoery gets allocated when the program
	    comes in RAM

	*/
	int *x = NULL;
	// Requesting memory for a new variable. nothrow signifies that if memory does
	// not get assigned it does not throw an error
	x = new(nothrow) int;
	if (!x) {
		cout << "Could not allocate memory\n";
	}
	else {
		*x = 22;
		cout << "Value of x is: " << *x << endl;
	}

	float *y = new(nothrow) float(11.111);
	if (!y) {
		cout << "Could not allocate memory\n";

	}
	else {
		cout << "Value of y is: " << *y << endl;
	}

	// DMA for Arrays
	int n = 10;
	int *a = new int[10];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	cout << "Array elements are: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	// Deallocating memory for variables
	delete x;
	delete y;

	// Deallocating memory for array
	delete []a;

}