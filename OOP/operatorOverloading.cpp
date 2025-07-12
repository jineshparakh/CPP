#include<bits/stdc++.h>
using namespace std;

class Complex {
private:
	int x, y;
public:
	Complex() {
		x = 0, y = 0;
	}
	Complex(int x, int y) {
		this->x = x, this->y = y;
	}
	void getData() {
		if (y >= 0)
			cout << "(" << x << "+" << y << "i)\n";
		else
			cout << "(" << x << "" << y << "i)\n";
	}
	void setData(int x, int y) {
		this->x = x, this->y = y;
	}
	Complex operator +(Complex &c) {
		Complex temp;
		temp.x = x + c.x;
		temp.y = y + c.y;
		return temp;
	}
	// Overloading unary operators
	Complex operator -() {
		Complex temp;
		temp.x = -x;
		temp.y = -y;
		return temp;
	}
	// Overloading pre-increment operator
	Complex operator ++() {
		Complex temp;
		temp.x = ++this->x;
		temp.y = ++this->y;
		return temp;
	}
	/*
	    Overloading post-increment operator
	    Why int is present as an argument?
	    --> This is done to help the compiler differentiate between pre and post increment operators after
	        being overloaded
	    --> Only 'int' should be written. Nothing else is acceptable (Else, this error occurs: no ‘operator++(int)’ declared for postfix ‘++’);
	*/
	Complex operator ++(int) {
		Complex temp;
		temp.x = this->x++;
		temp.y = this->y++;
		return temp;
	}
	/*
		Trying to overload << & >> operators without friend function
		Could not find a good way yet, it you get it do let me know!!
		More detailed explaination will be present in operatorOverloadingUsingFriendFunction.cpp
	*/
	istream& operator>>(istream& din) {
		cout << "Enter real part: ";
		din >> this->x;
		cout << "Enter imaginary part: ";
		din >> this->y;
		return din;
	}
	ostream& operator<<(ostream& dout) {
		if (y >= 0)
			dout << "(" << x << "+" << y << "i)\n";
		else
			dout << "(" << x << "" << y << "i)\n";

		return dout;
	}

};
int main() {
	/*
	    Operator Overloading:
	        --> When an operator is overloaded with multiple jobs, it is known as operator overloading
	        --> Way to implement compile time polymorphism
	    You cannot overload:
	    . (dot)
	    ::
	    ?:
	    sizeof

	*/
	Complex c1(2, 3), c2(3, 4), c3, c4, c5, c6, c7, c8;

	cout << "First complex number is: "; c1.getData();
	cout << "Second complex number is: "; c2.getData();
	// c1 will be the called object. While overloading binary operator, left object will be the caller object
	c3 = c1 + c2;
	cout << "Addition of first and second complex numbers is: "; c3.getData();
	c4 = c1.operator + (c2);
	cout << "Addition of first and second complex numbers(Different syntax) is: "; c4.getData();
	c5 = -c1;
	cout << "Negative of first complex number is: "; c5.getData();
	c6 = c1.operator - ();
	cout << "Negative of first complex number(Different Syntax) is: "; c6.getData();
	c7 = c1++;
	cout << "Result after Post increment operator overloading on first complex number is: "; c7.getData();
	cout << "After post incrememnt first complex number becomes: "; c1.getData();
	c8 = ++c2;
	cout << "Result after Pre increment operator overloading on second complex number is: "; c8.getData();
	cout << "After pre incrememnt second complex number becomes: "; c2.getData();

	/*
		Weird syntaxes after overloading << & >> without friend function :)
		You can uncomment and check if you want!
	*/

	// Complex c9;
	// c9 >> cin;
	// c9 << cout;
}