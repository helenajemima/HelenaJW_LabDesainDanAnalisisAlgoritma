#include <iostream> // file header input - output
using namespace std;

class contoh { // mendifinisi sebuah class bernama "contoh"
	private:
		int nilai; //mendefinisi sebuah integer bernama "nilai"
	
	public:
		contoh (int n) { //constructor yang mengambil integer "n"
			nilai = n; //inisialisasi "nilai" dengan nilai "n"
		}
		
		int getnum() {
			return nilai; // mengembalikan value 'nilai'
		}
};

int main () 
{
	contoh obj(10); //membuat class contoh bernama 'obj' dan meninisialisasi dengan nilai 10
	cout << "Nilai yang diinput : " << obj.getnum() << endl; 
	//mengeluarkan nilai yang dikembalikan oleh fungsi getnum() dari objek obj
	return 0;
}
