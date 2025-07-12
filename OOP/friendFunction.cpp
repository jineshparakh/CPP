#include<bits/stdc++.h>
using namespace std;

class Breadth;
class Length {
private:
	int l;
public:
	friend int area(Length, Breadth);
	void setL(int l) {
		this->l = l;
	}
	int getL() {
		return l;
	}
};
class Breadth {
private:
	int b;
	friend int area(Length, Breadth);
public:
	void setB(int b) {
		this->b = b;
	}
	int getB() {
		return b;
	}
};
int area(Length l1, Breadth b1) {
	return l1.l * b1.b;
}
int main() {
	/*
	    What is friend function?
	        --> Friend function is not a member function of a class to which it is a friend
	        --> It should be declared inside the class
	        --> It must be defined outside the class of which it is a friend
	        --> Since it is a friend to a class, it can access any of the members of that class
	            to which it is a friend, but not directly
	        --> It has no caller object
	        --> It should not be defined with membership label
	        --> It can be a friend to more than one class
	        --> You can declare a friend function anywhere in the class, access specifiers do not matter since it is a friend

	*/
	Length l;
	Breadth b;
	l.setL(2);
	b.setB(3);
	cout << area(l, b) << endl;

}