#include <iostream>
#include <vector>

using namespace std;

class graph { 
	private :
		int jumlahSimpul;
		vector<vector<int> > matriksKetetanggaan;
	
	public :
		graph(int simpul) 
		{
			jumlahSimpul = simpul;
			
			for (int i = 0; i < simpul; i++) 
			{
				vector <int> baris(simpul,0);
				matriksKetetanggaan.push_back(baris);
			}
		}
		
	void tambahSisi(int u, int v) 
	{
		if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul) {
			matriksKetetanggaan[u][v] = 1;
			matriksKetetanggaan[v][u] = 1;
		} else {
			cout << "Sisi tidak valid!" << endl;
		}
	}
	
	void hapusSisi(int u, int v) 
	{
		if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul) {
			matriksKetetanggaan[u][v] = 0;
			matriksKetetanggaan[v][u] = 0;
		} else {
			cout << "Sisi tidak valid!" << endl;
		}
	}
	
	void tampilkan() 
	{
		for (int i = 0; i < jumlahSimpul; i++) {
			for (int j = 0; j < jumlahSimpul; j++) {
				cout << matriksKetetanggaan[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int simpul = 5;
	graph Graph(simpul);
	
	Graph.tambahSisi(0, 1);
	Graph.tambahSisi(0, 4);
	Graph.tambahSisi(1, 2);
	Graph.tambahSisi(1, 3);
	Graph.tambahSisi(1, 4);
	Graph.tambahSisi(2, 3);
	Graph.tambahSisi(3, 4);
	
	cout << "Matriks Ketetanggaan : " << endl;
	
	Graph.tampilkan();
	
	Graph.hapusSisi(1, 3);
	
	cout << "Matriks Ketetanggaan setelah menghapus sisi antara 1 dan 3 : " << endl;
	
	Graph.tampilkan();
	
	return 0;
}
