#include<bits/stdc++.h>
using namespace std;

class Student {
	int rollNo;
	string name;
	class Address {
		int houseNo;
		string apartment;
		int pincode;
		string state;
	public:
		void setAddress(int houseNo, string apartment, int pincode, string state) {
			this->houseNo = houseNo;
			this->apartment = apartment;
			this->pincode = pincode;
			this->state = state;
		}
		void getAddress() {
			cout << "House No: " << houseNo << endl;
			cout << "Apartment: " << apartment << endl;
			cout << "Pincode: " << pincode << endl;
			cout << "State: " << state << endl;
		}
	};
	Address address;
public:
	void setData(int rollNo, string name, int houseNo, string apartment, int pincode, string state) {
		this->rollNo = rollNo;
		this->name = name;
		address.setAddress(houseNo, apartment, pincode, state);
	}
	void getData() {
		cout << "Student name: " << name << endl;
		cout << "RollNo: " << rollNo << endl;
		cout << "Address: ";
		address.getAddress();
	}
};

int main() {
	/*
	    --> A class inside a class is called nested class.
	    --> A nested class is a member and as such has the same access rights as other members
	    -->
	*/
	Student s1;
	s1.setData(1, "Jinesh", 22, "HouseApartments", 113111, "Maharashtra");
	s1.getData();
}