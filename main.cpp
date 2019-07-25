// File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "File.hpp"

using namespace std;
using namespace evt;

int main()
{
	string name = "Daniel";
	auto file = FileIO::plainText("C:\\Users\\kaumi\\Desktop\\test.txt"); // PlainTextFile
	file.write("hello!");
	cout << file.getline() << endl; // "hello!"
	file.write("\nother line");

	if (const auto line = file.safeGetline()) {
		cout << *line << endl; // hello!
	}
	if (const auto line = file.safeGetline()) {
		cout << *line << endl; // other line
	}

	cout << "this" << file.toString() << endl;
	cout << "that!" << PlainTextFileIO::toString("C:\\Users\\kaumi\\Desktop\\test.txt") << endl;
}
