#include<iostream>
#include<fstream>
using namespace std;

int main() {
	/*
	    File opening modes
	        --> ios:: in        input/read
	        --> ios:: out       output/write
	        --> ios:: app       append
	        --> ios:: ate       update
	        --> ios:: binary    binary


	*/
	ofstream fout; // Output Stream
	fout.open("fileHandling.txt");
	fout << "Hello World! (This was done using File Handling in C++)" << endl;
	fout << "Second line" << endl;
	fout.close();

	ifstream fin;
	fin.open("fileHandling.txt");
	string s;
	getline(fin, s);
	while (!fin.eof()) {
		cout << s << endl;
		getline(fin, s);
	}
}