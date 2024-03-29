#include <iostream>
#include <string>
using namespace std;

class kontak {
private:
    string nama[10];
    string telp[10];
    int count;

public:
    kontak() : count(0) {}

    void tambah(string name, string no) {
        if (count < 10) {
            nama[count] = name;
            telp[count] = no;
            count++;
        } 
    }

    void display() {
        cout << "\nDaftar Kontak:" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Kontak ke - " << i + 1 << endl;
            cout << "Nama : " << nama[i] << endl;
            cout << "Nomor Telepon : " << telp[i] << endl;
            cout << "------------------------------------\n";
        }
    }
};

int main() {
    string nm;
    string tlp;
    char choice;
    kontak orang;
    int index = 0;
    
    cout << "Masukkan kontak (maksimal 10 kontak)\n\n";

    do {
        cout << "Masukkan nama kontak ke - " << index + 1 << " : ";
        getline(cin, nm);
        cout << "Masukkan nomor telepon kontak ke - " << index + 1 << " : ";
        getline(cin, tlp);
        orang.tambah(nm, tlp);
        index++;
		cout <<"Kontak berhasil ditambahkan\n";	

        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> choice;
        cin.ignore(); 	
        cout << endl;

    } while (toupper(choice) == 'Y' && index < 10);

    if (toupper(choice) == 'N') {
        orang.display();
    }

    return 0;
}
