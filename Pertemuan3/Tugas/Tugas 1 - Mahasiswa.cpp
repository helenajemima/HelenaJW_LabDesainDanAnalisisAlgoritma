#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
public:
    string nama;
    int NPM;

public:
    void setNama(string n) {
        nama = n;
    }

    void setNPM(int p) {
        NPM = p;
    }

    string getNama() {
        return nama;
    }

    int getNPM() {
        return NPM;
    }
};

int main() {
    Mahasiswa mahasiswa[5]; 
    string name;
    int nim;

    for (int i = 0; i < 5; i++) {
    cout << "Masukkan nama mahasiswa " << i + 1 << ": ";
    getline(cin, name);
    mahasiswa[i].setNama(name);

    cout << "Masukkan NPM mahasiswa " << i + 1 << ": ";
    cin >> nim;
    cin.ignore();
    mahasiswa[i].setNPM(nim);
    }

    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa " << i + 1 << ":\n";
        cout << "Nama : " << mahasiswa[i].getNama() << endl;
        cout << "NPM : " << mahasiswa[i].getNPM() << endl;
    }

    return 0;
}

