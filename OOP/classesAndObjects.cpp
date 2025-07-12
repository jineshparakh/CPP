#include<bits/stdc++.h>
using namespace std;

class Point {
private:
	int x, y; // Called as instance member variables
public:
	// instance member functions
	void setData(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void getData();

	int getX() {
		return x;
	}

	int getY() {
		return y;

	}

	// Manhattan distance between 2 points
	int manhattanDistance(Point p) {
		return abs(x - p.x) + abs(y - p.y);
	}
};
/*
Point:: --> This thing is called membership label (Class name and then scope resolution operator)
*/
void Point::getData() {
	cout << "The coordinates of point are: (" << x << ", " << y << ")" << endl;
}
int main() {
	/*
	    Class is description of object (Basically blueprint)
		It is used to describe properties and behaviour of an object
	    Object is an instance of a class


	    Differences between classes and structures:
	        1. Access specifiers are public for structs by default and private for classes
	        2. Inheritance defaults to public for structs by default and private for classes

	    Except these, you can do everything in struct and class in similar fashion

	    Difference between defining a function inside the class and outside the class:
	        --> Functions defined inside the class are inline by default but when they are
	            defined outside the class, inline keyword has to be used explicitly to reuqest for
	            inline functionality

	    IMP: State of an object should only be changed by instance member functions. State here means values of member variables

	    Different names for Instance member variables: Attributes, data members, fields, properties, etc
	    Different names for Instance member functions: Methods, procedures, actions, operations, services, etc
	*/
	Point p1;
	p1.setData(2, 3);
	p1.getData();

	Point p2;
	p2.setData(4, 5);
	p2.getData();

	int distance = p1.manhattanDistance(p2);

	cout << "Manhattan distance between (" << p1.getX() << " ," << p1.getY() << ") and (" << p2.getX() << ", " << p2.getY() << ") is " << distance << endl;

}