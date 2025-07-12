#include<bits/stdc++.h>
using namespace std;

class Account {
	int balance;
	static float rateOfInterest; // Static member variable or Class variable
public:
	void setBalance(int balance) {
		this->balance = balance;
	}
	int getBalance() {
		return balance;
	}
	static float getRateOfInterest() {
		return rateOfInterest;
	}
	/*
	    We cannot use this pointer (->) with static static member functions
	    Example:
	    this->rateOfInterest=rateOfInterest is not correct and causes CE
	*/
	static void setRateOfInterest(float r) { // Static member function or Class member function
		rateOfInterest = r;
	}
};
/*
    The line below is extremely important for static member variables.
    Without this line an error will occur and we cannot access the value present in rateOfInterest
    Error if the line below is not present: undefined reference to `Account::rateOfInterest'

    We can also set some default value for the static variable. It is 0 by default
*/
float Account::rateOfInterest = 6.5f;
int main() {
	/*
	    Static Member Variables:
	        --> Declared inside the class body
	        --> Also known as class member variables
	        --> Should be defined outside the class (MANDATORY)
	        --> They do not belong to any object but belong to the entire class
	        --> Only one copy of static member variable for the whole class throughout the runtime of the program
	        --> They can also be used with classname
	        --> Memory for static member variable only gets alloted after member definition and not after declaration

	    Since static member variable is class variable, it can be accessed without an object
	    If it is a public member it can directly be accessed using className::staticaVariableName
	    But If it is private/ protected we need to have some functions to get and set the values

	    But if the function is a member function, then it can only be accessed using objects.
	    But we should be able to access static member variables without objects also.

	    Thus, static member functions come into picture

	    Static Member Functions:
	        --> Can only access static member variables
	        --> Can also be invoked without an object

	*/
	Account a1;
	a1.setBalance(200);
	cout << a1.getBalance() << endl;

	cout << Account::getRateOfInterest() << endl;
}