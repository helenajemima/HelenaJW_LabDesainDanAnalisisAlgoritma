#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
protected:
    string data;

public:
    Mahasiswa(string d) {
        data = d;
    }

    virtual void display() {
        cout << data << endl;
    }
};

class status : public Mahasiswa {
public:
    status(string d) : Mahasiswa(d) {}

    void display() {
        cout << "Status: " << data;
    }
};

class nama : public Mahasiswa {
public:
    nama(string d) : Mahasiswa(d) {}

    void display() {
        cout << ", Nama: " << data;
    }
};

class umur : public Mahasiswa {
public:
    umur(string d) : Mahasiswa(d) {}

    void display() {
        cout << ", Umur: " << data;
    }
};

class jurusan : public Mahasiswa {
public:
    jurusan(string d) : Mahasiswa(d) {}

    void display() {
        cout << ", Jurusan: " << data;
    }
};

class fakultas : public Mahasiswa {
public:
    fakultas(string d) : Mahasiswa(d) {}

    void display() {
        cout << ", Fakultas: " << data;
    }
};

int main() {
    string sta[10], na[10], um[10], jur[10], faku[10];
    int a;

    cout << "Masukan jumlah mahasiswa: ";
    cin >> a;
    cin.ignore();

    Mahasiswa* mahasiswa[a][5];

    for (int i = 0; i < a; i++) {
        cout << "\nMahasiswa " << i + 1 << endl;
        cout << "Status (Alumni / Mahasiswa Aktif): ";
        getline(cin, sta[i]);
        cout << "Nama: ";
        getline(cin, na[i]);
        cout << "Usia: ";
        getline(cin, um[i]);
        cout << "Jurusan : ";
        getline(cin, jur[i]);
        cout << "Fakultas : ";
        getline(cin, faku[i]);
        
        mahasiswa[i][0] = new status(sta[i]);
        mahasiswa[i][1] = new nama(na[i]);
        mahasiswa[i][2] = new umur(um[i]);
        mahasiswa[i][3] = new jurusan(jur[i]);
        mahasiswa[i][4] = new fakultas(faku[i]);
    }

    for (int i = 0; i < a; ++i) {
    	cout << "\n------------------------------------------------";
        cout << "\nData Mahasiswa ke-" << i + 1 << ":" << endl;
        for (int j = 0; j < 5; ++j) {
            mahasiswa[i][j]->display();
            delete mahasiswa[i][j]; 
        }
        cout << endl;
    }

    return 0;
}

