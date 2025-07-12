#include<iostream>
#include<fstream>
using namespace std;


int main() {
	/*

	    tellg()
	        --> Defined in istream class
	        --> It's prototype is
	                streampos tellg()
	        --> Returns the position of the current character in the input stream
	*/

	ifstream fin;
	fin.open("fileHandling.txt");
	int pos = fin.tellg();
	cout << pos << endl; //0
	char ch;
	fin >> ch;
	pos = fin.tellg();
	cout << pos << endl; //1
	fin >> ch;
	pos = fin.tellg();
	cout << pos << endl; //2
	fin.close();

	ofstream fout;
	fout.open("fileHandling.txt", ios::app);
	pos = fout.tellp();
	cout << pos << endl;

}