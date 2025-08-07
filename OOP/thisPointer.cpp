#include<bits/stdc++.h>
using namespace std;
class Point {
private:
	int x, y;
public:
	void setData(int x, int y) {
		/*
			If the passed agrs have same name as the class/struct args
			it is mandatory to use this pointer for non-initializer based
			constructor. Without this compiler would not be able to populate
			x, y (in this case).
		*/
		this->x = x;
		this->y = y;
	}
	void getData() {
		cout << "The coordinates of the point are: (" << x << "," << y << ")\n";
	}
};
int main() {
	/*
		Object Pointer
			--> Pointer which contains address of an object is called object pointer

		this Pointer
			--> 'this' is a keyword in C++
			--> this is a local object pointer in every instance member function and it contains the
				address of the caller object
			--> this pointer cannot be modified
			--> It is used to refer caller object in member function
	*/
	// p is an object pointer
	Point* p, p1;

	p = &p1;
	p->setData(2, 3);
	p->getData();
}