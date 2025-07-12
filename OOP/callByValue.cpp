#include<bits/stdc++.h>
using namespace std;

int findSum(int, int);
int main() {

	/*
	    When formal arguments are ordinary variables it is call by value
	*/

	int a = 2, b = 3;
	int sum = findSum(a, b); // a and b are actual arguments for findSum method
	cout << "Sum of " << a << " and " << b << " is: " << sum << endl;
}
// x and y are formal arguments and ordinary variables in this case. (Hence, call by value)
int findSum(int x, int y) {
	return x + y;
}