#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	public :
		string nama;
		int NPM;
		
	public :
		void setNama (string n) {
			nama = n;
		}
		
		void setNPM (int p) {
			NPM = p;
		}
		
		string getNama() {
			return nama;
		}
		
		int getNPM() {
			return NPM;
		}
};

int main () {
	Mahasiswa mhsw;
	string name;
	int nim;
	
	cout << "Masukkan nama mahasiswa : ";
	getline(cin,name);
	mhsw.setNama(name);

	cout << "Masukkan NPM mahasiswa : ";
	cin >> nim;

	mhsw.setNPM (nim);
	
	cout << "\nData Mahasiwa " << endl;
	cout << "Nama : " << mhsw.getNama();
	cout << "\nNPM : " << mhsw.getNPM();
	
	return 0;
	
	
}
