#include<bits/stdc++.h>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point() {
		x = 0, y = 0;
	}
	void setData(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void getData() {
		cout << "The coordinates of point are: (" << x << ", " << y << ")" << endl;

	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};
class Complex {
private:
	int x, y;
public:
	Complex() {
		x = 0, y = 0;
	}
	void setData(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void getData() {
		cout << "The complex number is: (" << x << "+" << y << "i)" << endl;

	}
	Complex(Point p) {
		this->x = p.getX();
		this->y = p.getY();
	}
};
int main() {
	/*
	    Class type to another class type can be implemented using:
	        1. conversion through constructor
	        2. conversion through casting operator


	*/
	Point p1;
	p1.setData(3, 4);
	Complex c1;
	/*
	    Constructor should be made in Complex class
	    Casting operator should be written in Point clas
	*/
	c1 = p1;
	c1.getData();
}
