#include <iostream>
#include <vector>

using namespace std;

class Graf {
    int jumlahSimpul;
    vector<vector<int> > daftarAdjasi;

	public:
		Graf(int simpul);
		void tambahkanTepi(int src, int dest);
		void cetakGraf();
	};
	
Graf::Graf(int simpul) 
{
	jumlahSimpul = simpul;
	daftarAdjasi.resize(simpul);
}
		    
void Graf::tambahkanTepi(int src, int dest) 
{
	daftarAdjasi[src].push_back(dest);
}
		    
void  Graf::cetakGraf() {
	for (int i = 0; i < jumlahSimpul; i++) {
		cout << "Daftar tetangga simpul " << i << " : ";
		
		for (size_t j = 0; j < daftarAdjasi[i].size(); ++j) {
			cout << daftarAdjasi[i][j] << " ";
		}
		    cout << endl;
	}
}

int main() {
	
	cout<<"Representasikan graf menggunakan daftar adjasi : " << endl ;
    
    Graf g(4);

    g.tambahkanTepi(0, 1);
    g.tambahkanTepi(0, 2);
    g.tambahkanTepi(1, 2);
    g.tambahkanTepi(2, 0);
    g.tambahkanTepi(2, 3);
    g.tambahkanTepi(3, 3);
   

    g.cetakGraf();

    return 0;
}
