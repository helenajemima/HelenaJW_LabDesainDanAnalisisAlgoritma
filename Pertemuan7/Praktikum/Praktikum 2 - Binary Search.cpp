#include <iostream>
#include <algorithm>
using namespace std;

const int n = 100;
int nim[n];

//fungsi untuk melakukan binary search
int binarysearch(int x, int l, int r) {
	if(r >= 1) {
		int mid = l + (r - 1) / 2;
		if (nim[mid] == x) 
			return mid;
		if (nim[mid] > x)
			return binarysearch(x, l, mid - 1);
		return binarysearch(x, mid + l, r);
	}
	return -1;
}

int main()
{
	int n;
	
	cout << "Masukkan jumlah mahasiswa : ";
	cin >> n;
	
	cout << "Masukkan NIM mahasiswa : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> nim[i];
	}
	
	//mengurutkan NIM mahasiswa
	sort(nim, nim + n);
	int x;
	cout << "Masukkan NIM yang dicari: ";
	cin >> x;
	
	int hasil = binarysearch(x, 0, n - 1);
	if(hasil == -1)
		cout << "NIM tidak ditemukan" << endl;
	else
		cout << "NIM ditemukan pada indeks " << hasil << endl;
		
	return 0;
}

