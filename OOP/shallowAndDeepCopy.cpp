#include<bits/stdc++.h>
using namespace std;

class ShallowCopy {
private:
	int x, y;
public:
	ShallowCopy() {
		x = 0, y = 0;
	}
	void setData(int x, int y) {
		this->x = x, this->y = y;
	}
	void getData() {
		cout << "X: " << x << ", Y: " << y << endl;
	}
	ShallowCopy(ShallowCopy &c) {
		x = c.x, y = c.y;
	}
};
class DeepCopy {
private:
	int x, y;
	int* p;
public:
	DeepCopy() {
		p = new int;
	}
	void setData(int x, int y, int z) {
		this->x = x;
		this->y = y;
		*p = z;
	}
	void getData() {
		cout << "X: " << x << ", Y: " << y << ", *P: " << *p << endl;

	}
	/*
	    Why is deep copy required?
	        --> In this class p is a pointer variable which will hold the address of an integer
	            memory block
	        --> So if we do normal copy as we do above, contents of p will be copied to new object.
	        --> This implies that the address of that integer variable (stored in p) will be copied.
	        --> So p from 2 different objects will have same *p
	        --> Hence, we need to declare a new int at runtime and then do a deep copy
	*/
	DeepCopy(DeepCopy &c) {
		x = c.x, y = c.y;
		p = new int;
		*(p) = *(c.p);
	}
	/*
	    Dangling pointer stuff:
	        --> So if the lifetime of an object is over and we do not explicitely delete the existance
	            of *p, it will be there in the memory with no access point.
	        --> It can cause unnecessary crashes and RTE.
	        --> So, deleting via a destructor is a good practice.
	*/
	~DeepCopy() {
		delete p;
	}
};


int main() {
	/*
	    How to create copy of an object?
	    --> Copy Constructor
	    --> Implicit copy assignment operator

	    Shallow Copy:
	        --> Creating copy of an object by copying data of all member variables as it is is called
	            shallow copy

	    Deep Copy:
	        --> Creating an object by copying data of another object along with the values of memory resources
	            which resides outside the object but are handled by the object.
	*/
	ShallowCopy shallow1;
	shallow1.setData(2, 3);
	ShallowCopy shallow2;
	shallow2 = shallow1;
	shallow2.getData();
	DeepCopy deep1;
	deep1.setData(4, 5, 6);
	DeepCopy deep2;
	deep2 = deep1;
	deep2.getData();


}