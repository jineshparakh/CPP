#include<bits/stdc++.h>
using namespace std;

// Abstract Class

/*
	Person can be thought of as an interface.
	Every derived class from Person has to implement all the
	pure virtual functions.

	C++ does not have any 'interface' keyword. Abstract classes
	using pure virtual functions help us create interfaces.

*/
class IPerson {
public:
	/*
		Virtual keyword is necessary because without this keyword, early binding of
		print() function occurs and hence base class function can be called using object
		pointers
	*/
	virtual void print() = 0;
};
/*
	For the inherited class, either we can override the pure virtual function of base class
	or declare the function as pure virtual in child class also.

	One of the two has to be done for sure
*/
class Student: public IPerson {

public:
	void print() {
		cout << "In Student Class\n";
	}
};

int main() {
	/*
		Pure Virtual Function
			--> A do nothing function is called Pure Virtual Function

		Abstract Class
			--> Any class which has one or more pure virtual functions is called Abstract class
			--> One cannot create an object of Abstract class (can't instanciate it)
	*/
	// IPerson p; // This is CE
	Student s;
	s.print();

}