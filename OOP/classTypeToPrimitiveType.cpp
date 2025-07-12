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
    // casting operator
	operator int() {
		return sqrt(x * x + y * y);
	}
};
int main() {
	/*
	    Class type to primitive type can be  implemented using casting operator
	    Syntax:
	        operator type(){
	            ...
	            return (type-data);
	        }

	*/
	Point p1;
	p1.setData(3, 4);
	int point;
	point = p1;
	cout << point << endl;
}
