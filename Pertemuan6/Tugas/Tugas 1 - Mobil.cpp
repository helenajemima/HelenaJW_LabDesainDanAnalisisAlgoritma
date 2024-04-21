#include <iostream>
using namespace std;

class Kendaraan {
protected:
    string merk;
    int tahunproduksi;

public:
    Kendaraan(string mrk, int thnpro) : merk(mrk), tahunproduksi(thnpro) {}

    void info() {
        cout << "Merk: " << merk << endl;
        cout << "Tahun Produksi: " << tahunproduksi << endl;
    }
};

class Mobil : public Kendaraan {
    int jmlhPintu;

public:
    Mobil(string merk, int thnproduksi, int jumpintu) : Kendaraan(merk, thnproduksi), jmlhPintu(jumpintu) {}

    void info() {
        Kendaraan::info(); 
        cout << "Jumlah pintu: " << jmlhPintu << endl;
    }
};

int main() {
    string merkMobil;
    int thnPro, jlhPintu;

    cout << "Masukkan merk mobil: ";
    getline(cin,merkMobil);
    cout << "Masukkan tahun produksi: ";
    cin >> thnPro;
    cout << "Masukkan jumlah pintu: ";
    cin >> jlhPintu;

    Mobil mobil(merkMobil, thnPro, jlhPintu);
    cout << "\nInformasi Mobil:" << endl;
    mobil.info();

    return 0;
}

