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


// auto is used because we do not know whether to have
// the return type as T1 or T2
template<typename T1, typename T2>
auto multiply(const T1& a, const T2& b) {
	return a * b;
}

// Another type for above
// In this we explicitly have the return type as typeof(a*b)
template<typename T1, typename T2>
auto multiply2(const T1& a, const T2& b) -> decltype(a*b) {
	return a * b;
}

int main() {
	/*
		Template:
			--> The keyword template is used to define function and class template
			--> It is a way to make any class or function generalized wrt data types
			--> It helps us avoid copy paste of code
			--> It serves as a blueprint for compiler to generate code for us.
	*/
	std::cout << maxx(2, 3) << std::endl;

	// same as the line above, this explicitly
	// calls integer function
	// Similar to vector<int>(..) declaration
	std::cout << maxx<int>(2, 3) << std::endl;

	std::cout << maxx(2.342, 31.121) << std::endl;
	std::cout << maxx<float>(2.342, 31.121) << std::endl;


	std::cout << multiply(3.3, 2.5) << std::endl;
	std::cout << multiply2(3.3, 2.5) << std::endl;

	std::cout << multiply(3, 2.43) << std::endl;


}