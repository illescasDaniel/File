#include <iostream>
#include "File.hpp"

using namespace std;

int main() {
	
	// Write
	File test1("rw.txt", ios::out);
	cout << test1.getFileName() << endl;
	
	test1 << "hello" << endl;
	
	// Read
	test1.open("rw.txt", ios::in);
	
	string read;
		
	File::getline(test1,read);
	cout << read << endl;
	
	// Write
	File b;
	b.open("rw2.txt", ios::out);
	b << "hi bro" << endl;
		
	b << "test 1" << endl;
	
	// Read
	b.open("rw2.txt", ios::in);
	
	cout << b.getline() << endl;
	
	string two;
	
	b >> two;
	cout << two << endl;
	
	b >> two;
	cout << two << endl;
	
	// Read
	File test2("rw2.txt", ios::in);
	
	cout << test2.toString() << endl;
	
	// Read and Write file in one line!
	cout << File::toString("rw2.txt") << endl;
	File::saveTextTo("test2.txt", "hello\nprogrammer");
	
	// EMPTY
	cout << "TEST EMPTY: " << endl;
	
	File test3;
	
	cout << test3.getFileName() << endl;
	cout << test3.getline() << endl;
	cout << test3.toString() << endl;
	test3 << "test";
	
	string s;
	test3 >> s;
	
	cout << s;
	
	return 0;
}
