#include<bits/stdc++.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(): x(0), y(0) {

	}
};
/*
    --> non-static const or reference data members cannot be initialized in a constructor
    --> They need to be initialized using initializer list
        or initialization during declaration (case of variable y)
*/
class DemoClass {
private:
	const int x;
	const int y = 5;
	int &z;
public:
	DemoClass(int &n): x(2), z(n) {

	}
};

int main() {
	/*
	    --> Initializer list is used to initialize data members of the class
	    --> The list of members to be initiated is indicated with a constructor as a comma separated list
	        followed by a colon (:)
	*/
	int num = 2;
	DemoClass d(num);
}