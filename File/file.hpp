#ifndef file_hpp
#define file_hpp

#include <fstream>
//

using namespace std;

class File {
	
private:
	fstream rw;
	
public:
	
	File();
	File(string name, ios_base::openmode mode);
	
	fstream & operator<< (string text);
	fstream & operator>> (string & text);
	
	void open (string name, ios_base::openmode mode);
	void close();
	
	~File();
	
	static void getline(File & file, string & name);
};

#endif /* file_hpp */
