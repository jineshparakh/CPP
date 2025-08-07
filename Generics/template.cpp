#include<bits/stdc++.h>
using namespace std;

// Function template or Generic template
template<class T>
T maxx(T a, T b) {
	if (a > b)
		return a;
	return b;
}

template<class X>
class ClassName {
	// Class elements
};
int main() {
	/*
	    Template:
	        --> The keyword template is used to define function and class template
	        --> It is a way to make any class or function generalized wrt data types
	*/
	cout << maxx(2, 3) << endl;
	cout << maxx(2.342, 31.121) << endl;
}