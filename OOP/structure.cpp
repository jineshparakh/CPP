#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x = 1; // Can initialize with some value in C++ but not in C
	int y = 1;
} p1;

struct Employee {

private:
	int eID;
	string name;
	int age;

public:
	// Structs can also have constructors
	Employee() {
		eID = 0;
		name = "";
		age = 0;
	}
	void getInputData() {
		cout << "Enter Employee ID, Employee name & Employee age: ";
		/*
		    No Need of '.' operator to access member variables. (It will actually give CE)
		    This (->) pointer can be used but no need as such
		*/
		cin >> eID >> this->name >> age;
	}
	void printData(); // You can also define functions outside the struct
};

void Employee::printData() {
	cout << "Hello " << name << ". Your Employee ID is " << eID << " and your age is " << age << endl;
}
int main() {
	/*
	    What is structure?
	        --> Collection of dissimilar elements
	        --> Way to group variables
	        --> Used to create user-defined Data Type
			--> Memory is only assigned when structure variable is declared and not when struct is defined

	    IMP: Writing the keyword struct before declaring a new structure variable is optional in C++
	         but mandatory in C


	    Some ways to create and initialize structure variable -->

	    Example struct:
	    struct myStruct(){
	        // member variables
	    } type1; ** First Type **

	    myStrcut type2={initialize here}; ** Second Type **
	    myStrcut type3; ** Third Type **
	    type3={initialize here}
	    myStrcut type4;
	    type4.someMemberVariable=someValue (Use of '.' operator) ** Fourth Type **

	    myStruct type5;

	    type5=type3  (Initialize with any other struct variable directly) ** Fifth Type **

	*/

	Point p2 = {2, 3};
	Point p3;
	p3 = {4, 5};
	Point p4;
	p4.x = 6, p4.y = 7;

	/*
	    In C, structs could not have member functions but they can have in C++.
	    This is the beginning step to achieve encapsulation
	    (See Struct Employee)

	    IMP:
	        1. Struct can also have access specifiers public, private and protected
	            (See Employee struct)
	        For Difference between classes and structs see clasesAndObjects.cpp file
	*/

	Employee e1;
	e1.getInputData();
	e1.printData();

	Employee e2;
	e2.printData(); // Values set in constructor will get printed
	
}