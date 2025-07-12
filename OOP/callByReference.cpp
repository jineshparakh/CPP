#include<bits/stdc++.h>
using namespace std;

int findSum(int&, int&);
int main() {

	/*
	    When formal arguments are reference variables it is call by reference
	*/

	int a = 2, b = 3;
	int sum = findSum(a, b); // References of a and b are passed
	cout << "Sum of " << a << " and " << b << " is: " << sum << endl;
}
// x and y are formal arguments and reference variales in this case. (Hence, call by reference)
int findSum(int &x, int &y) { //
	return x + y;
}