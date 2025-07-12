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

	friend Complex operator +(Complex&, Complex&);

	// Overloading unary operators
	friend Complex operator -(Complex&);

	// Overloading pre-increment operator
	friend Complex operator ++(Complex&);

	/*
	    Overloading post-increment operator
	    Why int is present as an argument?
	    --> This is done to help the compiler differentiate between pre and post increment operators after
	        being overloaded
	    --> Only 'int' should be written. Nothing else is acceptable (Else, this error occurs: no ‘operator++(int)’ declared for postfix ‘++’);
	*/
	friend Complex operator ++(Complex&, int);

	/*
		Let us understand use and need of each keyword?
			--> friend is there to make the overloaded operator functions as a friend to Complex class
			--> istream& and ostream& are present as return types to facilitate multiple cin's and cout's together
				Example: cin>>c1>>c2>>c3; or cout<<c1<<c2<<c3;
			--> Why the reference(&) is mandatory?
				--> We cannot directly create objects of istream and ostream class because they are declared as
					protected in the base classes
				--> Thus a reference is passed do that concatenation of multiple cin's or cout's is possible
			--> Why Complex& in istream and Complex in ostream?
					--> Beacuse we need to alter or manipulate the actual values while taking the input
						and not during the output
					--> Both can be of type Complex& . There is not problem in that :)
	*/
	friend istream& operator >>(istream&, Complex&);

	friend ostream& operator <<(ostream&, Complex);


};

Complex operator +(Complex &c1, Complex &c2) {
	Complex temp;
	temp.x = c1.x + c2.x;
	temp.y = c1.y + c2.y;
	return temp;
}

Complex operator -(Complex &c) {
	Complex temp;
	temp.x = -c.x;
	temp.y = -c.y;
	return temp;
}

Complex operator ++(Complex &c) {
	Complex temp;
	temp.x = ++c.x;
	temp.y = ++c.y;
	return temp;
}

Complex operator ++(Complex &c, int) {
	Complex temp;
	temp.x = c.x++;
	temp.y = c.y++;
	return temp;
}

istream& operator >>(istream& din, Complex &c) {
	cout << "Taking complex number as input....\n";
	cout << "Enter real part: ";
	din >> c.x;
	cout << "Enter imaginary part: ";
	din >> c.y;
	return din;
}

ostream& operator <<(ostream& dout, Complex c) {
	if (c.y >= 0)
		dout << "(" << c.x << "+" << c.y << "i)\n";
	else
		dout << "(" << c.x << "" << c.y << "i)\n";
	return dout;
}

int main() {

	Complex c1(2, 3), c2(3, 4), c3, c4, c5, c6, c7, c8;

	cout << "First complex number is: "; c1.getData();
	cout << "Second complex number is: "; c2.getData();
	// c1 will be the called object. While overloading binary operator, left object will be the caller object
	c3 = c1 + c2;
	cout << "Addition of first and second complex numbers is: "; c3.getData();
	c4 = operator + (c1, c2);
	cout << "Addition of first and second complex numbers(Different syntax) is: "; c4.getData();
	c5 = -c1;
	cout << "Negative of first complex number is: "; c5.getData();
	c6 = operator - (c1);
	cout << "Negative of first complex number(Different Syntax) is: "; c6.getData();
	c7 = c1++;
	cout << "Result after Post increment operator overloading on first complex number is: "; c7.getData();
	cout << "After post incrememnt first complex number becomes: "; c1.getData();
	c8 = ++c2;
	cout << "Result after Pre increment operator overloading on second complex number is: "; c8.getData();
	cout << "After pre incrememnt second complex number becomes: "; c2.getData();


	Complex c9;
	cin >> c9;
	cout << "The complex number taken as input is: " << c9;
}