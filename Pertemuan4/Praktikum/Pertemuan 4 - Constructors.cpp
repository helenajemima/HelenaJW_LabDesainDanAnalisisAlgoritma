#include <iostream>
#include <string>

using namespace std;
class pelajaran { //class name
	public : //access specifier
		pelajaran () { //constructor
			cout << "Ini adalah mencari materi C++ tentang constructors!";
		}
};

int main ()
{
	pelajaran obj; //membuat ocject dari sebuah class
	return 0;
}
