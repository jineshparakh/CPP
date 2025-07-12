#include<bits/stdc++.h>
using namespace std;

// Assigning default values starts from right side
int add(int, int, int = 0);
int main() {
	int a = 2, b = 3, c = 5;
	cout << "Addition of " << a << " and " << b << " is: " << add(a, b) << endl;
	cout << "Addition of " << a << ", " << b << " and " << c << " is: " << add(a, b, c) << endl;
}
int add(int x, int y, int z) {
	return x + y + z;
}