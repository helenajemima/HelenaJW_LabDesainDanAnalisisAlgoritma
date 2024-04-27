#include <iostream>
#include <string>
using namespace std;

struct barang {
	string barang;
	int harga;
};

int search(const barang daftar[], string brg) {
	for(int i = 0; i < 5; i++) {
		if (daftar[i].barang == brg) {
			return i;
		}
	}	
	return -1;
}

int main()
{
	string brg;
	bool ketemu;

	barang daftarbarang[5] {
	{"Buku", 5000}, 
	{"Pensil", 1000}, 
	{"Pulpen", 2000}, 
	{"Penghapus", 500}, 
	{"Penggaris", 1500}
	};
	
	cout << "Masukkan nama barang yang ingin dicari = ";
	cin >> brg;
	
	int a = search(daftarbarang, brg);
	
	
		if (a != -1)  {
			cout << "Barang " << daftarbarang[a].barang << " ditemukan dengan harga " << daftarbarang[a].harga;			
		} else {
			cout << "Maaf, barang "<< brg << " tidak ditemukan dalam daftar";
		}
}

