#include <iostream>
using namespace std;

class BangunDatar {
protected:
    float lebar, tinggi;

public:
    virtual float luas() = 0; 
    void setvalue(float a, float b) {
        lebar = a;
        tinggi = b;
    }
};

class PersegiPanjang : public BangunDatar {
public:
    float luas() {
        return (lebar * tinggi);
    }
};

class Segitiga : public BangunDatar {
public:
    float luas() {
        return (lebar * tinggi / 2);
    }
};

class Persegi : public BangunDatar {
public:
    float luas() {
        return (lebar * lebar);
    }
};

int main() {
    float pjg, lbr, alas, tgg, sisi;

    cout << "Masukkan panjang persegi panjang : ";
    cin >> pjg;
    cout << "Masukkan lebar persegi panjang : ";
    cin >> lbr;
    cout << "Masukkan alas segitiga : ";
    cin >> alas;
    cout << "Masukkan tinggi segitiga : ";
    cin >> tgg;
    cout << "Masukkan sisi persegi : ";
    cin >> sisi;

    PersegiPanjang pp;
    pp.setvalue(lbr, pjg);
    Segitiga tri;
    tri.setvalue(alas, tgg);
    Persegi square;
    square.setvalue(sisi, sisi);

    cout << "\nLuas Bangun Datar : " << endl;
    cout << "Luas persegi panjang : " << pp.luas() << endl;
    cout << "Luas segitiga : " << tri.luas() << endl;
    cout << "Luas persegi : " << square.luas() << endl;

    return 0;
}

