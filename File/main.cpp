#include <iostream>
#include "File.hpp"

#include <fstream>

using namespace std;

//
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
	
	
	File b;
	b.open("rw.txt", ios::out);
	
	b << "hi bro";
	
	return 0;
}
