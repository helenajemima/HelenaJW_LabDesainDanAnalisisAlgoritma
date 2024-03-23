#include <iostream>
using namespace std;

class silsilah {
	protected:
		string orangtua = "Albert Wijaya dan Jenny Lim";
		string anakanak = "Agatha Wijaya dan Jonathan Widjaja";
	
	public : 
	string cekSilsilah() {
		//mengubah teks statis menjadi teks yang mengekstrak nama orangtua dari variabel yang sudah ada
		return "Ayah bernama " + orangtua.substr(0, orangtua.find(" ")) +
			" dan Ibu bernama " + orangtua.substr(orangtua.find(" ") + 4);
	}
};

class cucu : public silsilah {
	protected : 
	string cucu = "Wilbert Tan dan Rayanza Wijaya";
	
	public:
		string cekAnak() {
			//mengubah teks statis menjadi teks yang mengekstrak nama anakanak dari variabel yang sudah ada
			return "Anak pertama keluarga Wijaya adalah " + anakanak.substr(0, anakanak.find(" ")) +
				" dan anak kedua dari keluarga Wijaya adalah " + anakanak.substr(anakanak.find(" ") + 4);
		}
};

class anak : public cucu {
	public : 
	string lihatSilsilahnya() {
		return "Silsilah Keluarga Wijaya";
	}
	
	string cekCucu() {
			//mengubah teks statis menjadi teks yang mengekstrak nama cucu dari variabel yang sudah ada
		return "Cucu pertama bernama " + cucu.substr(0, cucu.find(" ")) +
			" dan cucu kedua bernama " + cucu.substr(cucu.find(" ") + 4);
	}
};

int main ()
{
	anak SilsilahWijaya;
	
	//output hasil dari metode - metode dalam kelas anak
	cout << SilsilahWijaya.lihatSilsilahnya() << endl;
	cout << SilsilahWijaya.cekSilsilah() << endl;
	cout << SilsilahWijaya.cekAnak() << endl;
	cout << SilsilahWijaya.cekCucu() << endl;
	
	return 0;
}
