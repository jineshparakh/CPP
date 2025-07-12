#include<bits/stdc++.h>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point() {
		x = 0, y = 0;
	}
	Point(int k) {
		x = k, y = k;
	}

	void setData(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void getData() {
		cout << "The coordinates of point are: (" << x << ", " << y << ")" << endl;

	}
};
int main() {
	/*
	    Primitive type to class type can be  implemented using parametrized constructor
	*/
	Point p1;
	int point = 5;
	p1 = 5; // Paramertrized constructor gets called here
	p1.getData();
}
