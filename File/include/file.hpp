#pragma once

#include <fstream>

using namespace std;

class File {
	
private:
	
	fstream rw;
	string name;
	void close();
	
public:
	
	File();
	File(const string& name, const ios_base::openmode& mode);
	
	void open(const string& name, const ios_base::openmode& mode);

	fstream & operator<<(const string& text);
	fstream & operator>>(string& text);

	string getFileName() const;
	string getline();
	string toString();
	
	~File();
	
	static string toString(const string& name);
	static void saveTextTo(const string& fileName, const string& text);
	static void getline(File& file, string& name);
};
