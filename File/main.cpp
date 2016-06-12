#include <iostream>
#include "File.hpp"

#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
	
	// Write
	File prueba("rw.txt", ios::out);
	
	prueba << "hello" << endl;
	
	// Read
	prueba.open("rw.txt", ios::in);
	
	string read;
	
	// prueba >> read;
	File::getline(prueba,read);
	
	cout << read << endl;
	
	// Write
	File b;
	b.open("rw.txt", ios::out);
	
	b << "hi bro" << endl;
	
	b << "test 1";

	// Read
	b.open("rw.txt",ios::in);
	
	string two;
	b >> two;
	
	cout << two << endl;
	
	// Read
	File test2("rw.txt",ios::in);
	 
	string s;
	test2 >> s;
	 
	cout << s << endl;
	
	return 0;
}
