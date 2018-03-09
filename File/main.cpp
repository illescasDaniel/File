#include <iostream>
#include "File.hpp"

using namespace std;
using namespace evt;

#if (__cplusplus >= 201406)
	#include <experimental/optional>
	using namespace experimental;
#endif

int main() {
	
	//auto myTestFile = File::openInBinary("/Users/Daniel/Desktop/MyFile.bin");
	//myTestFile.writeInBinary(10);
	//myTestFile.writeInBinary("HolaA"s, false); //
	
	//cout << myTestFile.readFromBinary<int>() << endl;
	//cout << myTestFile.readFromBinary<string>(4) << endl;
	
	//cout << myTestFile.toString() << endl;
	
	//myTestFile.writeInBinary(10);
	
	// C++17 example
	
    #if (__cplusplus >= 201406)
	
		File stack("name.txt");
		stack.write("name=Daniel\nage=20");
	
		optional<string> readContent;
	
		int age {};
		string name {};
	
		while ((readContent = stack.safeGetline()) != nullopt) {
			
			string content = *readContent;
			
			if (size_t position = content.find("="); position != string::npos) {
				
				string variableName = content.substr(0, position);
				string variableValue = content.substr(position+1, content.size()); // string must have a value... else we should check if position+1 is correct
				
				if (variableName == "name") {
					name = variableValue;
				}
				else if (variableName == "age") {
					age = stoi(variableValue);
				}
			}
		}
		cout << "My name is: " << name << ", my age is: " << age << endl;
	
    #endif
	
	File test2("111.txt");
	test2.write("Holaa!! :D\n");
	test2.write("Hello");
	
	cout << test2.getline() << endl;
	cout << test2.read() << endl;
	
	test2.seekInputPosition(0);
	
	cout << test2.getline() << endl;
	
	test2.open("222.bin");
	test2.writeInBinary<int>(2000);
	//test2.seekPosition(1); // now it writes at position 1, but also changes the property "writeAtEnd"!
	test2.writeInBinary<string>("test");
	test2.writeInBinary<float>(9.8);
	
	cout << test2.readFromBinary<int>() << endl;
	cout << test2.readFromBinary<string>(4) << endl;
	cout << test2.readFromBinary<float>() << endl;
	
	test2.seekInputPosition(0);
	cout << test2.readFromBinary<int>() << endl;
	
	File::saveTextTo("3333.txt", "Hi, this is a teasdfst!");
	cout << "TO STRING: " << File::toString("3333.txt") << endl;
	
	return 0;
}
