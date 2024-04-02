#include <iostream>
using namespace std;

float tambah (float a, float b) {
	return a + b;
}

float kurang (float a, float b) {
	return a - b;
}

float kali (float a, float b) {
	return a * b;
}

float bagi (float a, float b) {
	if (b == 0) {
		cout << "ERROR! \nHasil pembagian = Error. Pembagian dengan nol tidak dapat dilakukan\n";
	} else {
		return a / b;	
	}

}

int main () 
{
	float num1, num2;
	char choice, lanjut;
	
	do {
	cout << "Masukkan dua angka = ";
	cin >> num1 >> num2;
	
	cout << "Pilih operasi (+ untuk tambah. - untuk kurang. * untuk kali. / untuk bagi) : ";
	cin >> choice;	
		
	switch(choice){
	case '+':
      cout << "Hasil pertambahan = " << tambah(num1, num2);
      break;

    case '-':
      cout << "Hasil pengurangan = " << kurang(num1, num2);
      break;

    case '*':
      cout << "Hasil perkalian = " << kali(num1, num2);
      break;

    case '/':
      cout << "Hasil pembagian = " << bagi(num1, num2);
      break;
    }	
    
    cout << "\nTambahkan kontak lagi? (y/n): ";
    cin >> lanjut;
		
	} while (toupper(lanjut) == 'Y');

	return 0;
}



