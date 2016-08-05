#include "file.hpp"
#include <string>

File::File() {
	name = "";
}

File::File(string name, ios_base::openmode mode) {
	open(name,mode);
}

fstream & File::operator<<(string text) {
	if (rw.is_open())
		rw << text;
	
	return rw;
}

fstream & File::operator>>(string & text) {
	if (rw.is_open())
		rw >> text;
	
	return rw;
}

void File::open(string name, ios_base::openmode mode) {
	
	this->name = name;
	
	close();
	rw.open(name,mode);
	
	if (rw.fail()) {
		printf("File couldn't be open");
	}
}

void File::close() {
	if (rw.is_open())
		rw.close();
}

File::~File() {
	close();
}

string File::getFileName() {
	return name;
}

string File::getline() {
	
	string s;
	std::getline(rw,s);
	
	return s;
}

void File::toFile(string name, string text) {
	File write(name,ios::out);
	write << text;
}

string File::toString() {

	open(this->name,ios::in);

	string s2;
	
	while(!rw.eof())
		s2 += getline() + '\n';
	
	return s2;
}

string File::toString(string name) {
	
	File read(name,ios::in);
	return read.toString();
}

void File::getline(File & file, string & name) {
	std::getline(file.rw,name);
}