#include <iostream>
#include "File.hpp"

using namespace std;
using namespace evt;

int main() {
	
	File test2("111.txt");
	test2.write("Holaa!! :D\n");
	test2.write("Hello");
	
	cout << test2.getline() << endl;
	cout << test2.read() << endl;
	
	test2.open("222.bin");
	test2.writeInBinary<int>(2000);
	//test2.seekPosition(1); // now it writes at position 1, but also changes the property "writeAtEnd"!
	test2.writeInBinary<string>("test");
	test2.writeInBinary<float>(9.8);
	
	cout << test2.readFromBinary<int>() << endl;
	cout << test2.readFromBinary<string>(4) << endl;
	cout << test2.readFromBinary<float>() << endl;
	
	File::saveTextTo("3333.txt", "Hi, this is a teasdfst!");
	cout << File::toString("3333.txt") << endl;
	
	return 0;
}
