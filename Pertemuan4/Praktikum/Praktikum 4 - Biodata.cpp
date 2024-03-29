#include <iostream>
#include <string>
using namespace std;

class biodata  {
	private:
		string nama;
		int umur;
		string alamat;
	
	public:
		biodata(string name, int age, string add)
		: nama(name), umur(age), alamat(add)
		{
			cout << "Constructor dipanggil";
		}
		
		~biodata() {
			cout <<"\nDestructor dipanggil";
		}
		
		void display() {
		cout << "\n\nInformasi biodata" << endl;
		cout << "Nama : "<<nama<<" \nUmur : "<<umur<<" \nAlamat : "<<alamat<<"";			
		}
};

int main() 
{
	int u;
	string n, a;
	
	cout << "Masukkan nama anda : ";
	getline(cin,n);
	cout << "Masukkan usia anda : ";
	cin >> u;
	cout << "Masukkan alamat anda : ";
	cin.ignore();
	getline(cin,a);
	
	{
		biodata obj;	
		obj.display();
	}	


	return 0;
}
