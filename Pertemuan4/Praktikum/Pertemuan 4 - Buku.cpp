#include <iostream>
#include <string>
using namespace std;

class infobuku {
	private:
		string judul;
		string penulis;
		int tahun;
	
	public:
		infobuku() {
			judul = "Unknown";
			penulis = "Unknown";
			tahun = 0;
		}
		
		void setjudul(string title) {
			judul = title;
		}

		void setpenulis (string author) {
			penulis = author;
		}

		void settahun(int year) {
			tahun = year;
		}
	
	void displayinfobuku() {
		cout << "Judul : " << judul << endl;
		cout << "Penulis : " << penulis << endl;
		cout << "Tahun terbit : " << tahun << endl;
	}
};

int main () 
{
	infobuku bebas;
	infobuku terserah;
	
	bebas.setjudul("Harry Potter and the Philosopher's Stone");
	bebas.setpenulis("J.K. Rowling");
	bebas.settahun(1997);
	
	terserah.setjudul("To Kill a Mockingbird");
	terserah.setpenulis("Harper Lee");
	terserah.settahun(1960);
	
	cout << "Informasi buku 1 : " << endl;
	bebas.displayinfobuku();
	cout << "-------------------------------------";
	
	cout << "\n\nInformasi buku 2 : " << endl;
	terserah.displayinfobuku();
	cout << "-------------------------------------";
	
	return 0;
}
