// File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "File.hpp"

using namespace std;
using namespace evt;

int main()
{
	auto textFile = FileIO::plainText("C:\\Users\\kaumi\\Desktop\\test1.txt");
	textFile.write("Hello ");
	textFile.write("world");
	cout << textFile.read() << endl;
	cout << textFile.read() << endl;
	textFile.write("123");
	cout << textFile.readWithOffset(11) << endl;

	//cout << textFile.getline() << endl;
	if (const auto line = textFile.safeGetline()) {
		cout << *line << endl;
	}

	cout << "that!" << PlainTextFileIO::toString("C:\\Users\\kaumi\\Desktop\\test1.txt") << endl;

	auto binaryFile = FileIO::binary("C:\\Users\\kaumi\\Desktop\\test3.dat"); // Binary
	binaryFile.write<int>(984023);
	binaryFile.write<int>(123);
	binaryFile.write<double>(12.3);
	cout << binaryFile.read<int>() << endl;
	cout << binaryFile.read<int>() << endl; // same as above
	cout << binaryFile.read<double>() << endl;

	binaryFile.write<int>(999);
	cout << binaryFile.readWithOffset<int>(4 + 4 + 8) << endl;
	
	binaryFile.write<std::string>("Daniel");
	binaryFile.write<std::string>("Illescas");
	cout << binaryFile.readWithOffset<string>(8, 4 + 4 + 8 + 4 + 6) << endl;
}
