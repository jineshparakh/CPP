#include<iostream>
#include<fstream>
using namespace std;

int main() {
	/*
	    seekg()  (get pointer)
	        --> Defined in istream class
	        --> Prototype:
	            - istream& seekg(streampos pos);
	            - isteeam& seekg(streamoff off, ios_base::seekdir way);

	            --> pos is the new absolute position within the stream (relative to the beginning)
	            --> off is the offset value, relative to the way parameter
	            --> way values (one of the 3) --> ios_base::beg, ios_base::cur and ios_base::end

	    seekp()  (put pointer)
	        --> Defined in ostream class
	        --> Prototype:
	            - ostream& seekg(streampos pos);
	            - ostream& seekg(streamoff off, ios_base::seekdir way);

	            --> pos is the new absolute position within the stream (relative to the beginning)
	            --> off is the offset value, relative to the way parameter
	            --> way values (one of the 3) --> ios_base::beg, ios_base::cur and ios_base::end
	*/

	cout << "For seekg()..\n\n";
	ifstream fin;
	fin.open("fileHandling.txt");
	if (fin.tellg() == -1) {
		cout << "Could not open the file\n";
		exit(0);
	}
	cout << "File Opened Successfully\n";
	cout << "Tellg position: " << fin.tellg() << endl;
	cout << "First char from the file: " << (char)fin.get() << endl;
	cout << "Second char from the file: " << (char)fin.get() << endl;
	cout << "Tellg position: " << fin.tellg() << endl;
	cout << "Making tellg again point to start of the file..\n";
	fin.seekg(2);
	cout << "Tellg position: " << fin.tellg() << endl;
	cout << "Third char from the file: " << (char)fin.get() << endl;
	cout << "Making tellg move 7 positions ahead from current..\n";
	fin.seekg(7, ios_base::cur);
	cout << "Tellg position: " << fin.tellg() << endl;
	cout << "Char from the file: " << (char)fin.get() << endl;
	fin.close();

	cout << "For seekp()\n\n";
	ofstream fout;
	fout.open("fileHandling.txt", ios::ate | ios::app);
	cout << "Tellp position: " << fout.tellp() << endl;
	cout << "Making tellp point to 4 position to the right of beginning..\n";
	fout.seekp(4, ios_base::beg);
	cout << "Tellp position: " << fout.tellp() << endl;

}