#include "file.hpp"
#include <string>

File::File(){}

File::File(string name, ios_base::openmode mode){
	open(name,mode);
}

fstream & File::operator<<(string text){
	if (rw.is_open())
		rw << text;
	
	return rw;
}

fstream & File::operator>>(string & text){
	if (rw.is_open())
		rw >> text;
	
	return rw;
}

void File::open(string name, ios_base::openmode mode){
	close();
	rw.open(name,mode);
}


void File::close(){
	if (rw.is_open())
		rw.close();
}

File::~File(){
	close();
}

void File::getline(File & file, string & name){
	std::getline(file.rw,name);
}