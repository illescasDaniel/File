#ifndef file_hpp
#define file_hpp

#include <fstream>

using namespace std;

class File {
	
private:
	
	fstream rw;
	string name;
	void close();
	
public:
	
	File();
	File(string name, ios_base::openmode mode);
	
	fstream & operator<< (string text);
	fstream & operator>> (string & text);
	
	void open (string name, ios_base::openmode mode);
	
	~File();
	
	
	string toString();
	static string toString(string name);
	
	static void toFile(string name, string text);
	
	string getline();
	static void getline(File & file, string & name);
	
	string getFileName();
	
};

#endif /* file_hpp */
