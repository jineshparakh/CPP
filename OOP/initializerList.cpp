#include<bits/stdc++.h>
using namespace std;

/*
	Without initializer lists, object creation is two steps:
	1. Allocate memory for the object
	2. Based on the constructor, populate the values

	With initializer lists, both these things are done in a single step

	IMP:
	--> non-static const or reference data members cannot be initialized in a constructor
		cause const can't be changed once assigned
	--> They need to be initialized using initializer list
		or initialization during declaration (case of variable y)
	--> Order of initialization: Same as the variable definition order i.e. x, y and then z
*/
class DemoClass {
private:
	const int x;
	const int y = 5;
	int& z;
public:
	DemoClass(int& n): x(2), z(n) {

	}
};

class Vector3f {
private:
	float x, y, z;
public:

	/*
		x=1.0, y=2.0, z=3.0
	*/
	Vector3f(): x(1.0), y(2.0), z(3.0) {

	}

	/*

	Let's see another initialization:
	Vector3(): x(y), y(2.0), z(3.0) {
	}

	In this case, x will be some random value,
	y will be 2.0, z will be 3.0
	--> This is because order of initialization is
		same as order of definition i.e. x, y, z
		In this case x depends on y but y will be
		initialized after x causing undefined beheviour
	*/
};

int main() {
	/*
		--> Initializer list is used to initialize data members of the class
		--> The list of members to be initiated is indicated with a constructor as a comma separated list
			followed by a colon (:)
	*/
	int num = 2;
	DemoClass d(num);

	Vector3f vec;
}