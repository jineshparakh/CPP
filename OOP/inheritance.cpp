#include<bits/stdc++.h>
using namespace std;
class A {
private:
	int x;
protected:
	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}
};
class B: public A {
public:
	void setData(int x) {
		setX(x);
	}
	int getData() {
		return getX();
	}
};
int main() {
	/*
	    What is inheritance?
	        --> It is a process of inheriting properties and behaviours of existing class(es) into new class(es)
            --> A more generalized class is always the parent and the specific one is always the child
                Example:
                    Class Fruit will be a parent class
                    Class Apple will be a child class

	    Need of inheritance?
	        --> Let us understand this via and example. Suppose you have a class Car. You also wish to have a class
	            SportsCar which has all the properties of Car + some exclusive properties for it being a SportsCar
	        --> What we can do for this?
	            --> We can have 2 seperate classes, Car (With original properties)
	                and SportsCar (With the new properties + properties of car). Issue in this is that we will have to write
	                same code twice for Car and SportsCar for the common features
	            --> We can have 2 seperate classes, Car (With original properties) and SportsCar (With the new properties)
	                and then whenever we need to add a new SportsCar we make 2 objects for it. One for new features of a Sports
	                Car and general features of a Car. Issue with this is that it does not comply with the idea of Encapsulation
	                which states that for any entity all of it's variables and functions should be part of the same class

	        So to solve these problems, the concept of inheritance comes into picture.
	        We can reuse the properties of a previously declared class and use them in our new class with some
	        additional functionalities

	    Syntax:
	        class BaseClassName{

	        };

	        class DerivedClassName : VisibilityMode/AccessSpecifier BaseClassName{

	        };

	    Types of Inheritance:
	        1. Single Inheritance
	            --> 1 parent class and 1 child class
	                Example:
	                    Class A{

	                    };
	                    class B:public A{

	                    };
	        2. Multilevel Inheritance
	            --> More than one level of single inheritance
	                Example:
	                    Class A{

	                    };
	                    Class B: public A{

	                    };
	                    class C: public B{

	                    };
	        3. Multiple Inheritance
	            --> More than one parent class
	                Example:
	                    Class A{

	                    };
	                    Class B{

	                    };
	                    Class C: public A, public B{

	                    };
	        4. Hierarchical Inheritance
	            --> One parent having more than one children
	                Example:
	                    Class A{

	                    };
	                    Class B: public A{

	                    };
	                    Class C: public A{

	                    };
	        5. Hybrid Inheritance
	            --> Mixture of more than one type of inheritance from 1 to 4

	    Visibility Modes
	        --> Private
	        --> Protected
	        --> Public

	    Types of users for a class
	        --> Users who create an object of the class (say u1)
	        --> Users who use derived class to access members of base class (say u2)

	    Difference between availability & accessibility?
	        --> During inheritance everything is inherited may it be Private or Protected or Public.
	            They are avaiable in the derived class and availalibility does not depend on the visibility mode
	            of inheritance.
	            When we say they are available, it does not mean that everyone can access it. They might not
	            be accessible depending on the visibility mode

	    Access specifier in base class | Access specifier when inherited publicly
	    Public						   | Public
	    Protected	 				   | Protected
	    Private						   | Inaccessible


	    Access specifier in base class | Access specifier when inherited protectedly
	    Public						   | Protected
	    Protected					   | Protected
	    Private						   | Inaccessible


	    Access specifier in base class	| Access specifier when inherited privately
	    Public						    | Private
	    Protected						| Private
	    Private							| Inaccessible
	*/

	B b;
	b.setData(4);
	cout << b.getData() << endl;
}