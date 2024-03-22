// --------------------------------- QUICK SORT -----------------------------------------------
#include <iostream> //file header input - output 
using namespace std;

//function untuk menukar/swap 2 elemen di dalam array
void swap (int arr[], int pos1, int pos2) { //mendefinisi function untuk menukar elemen - elemen di array
	int temp; //mendeklarasi temp dengan tipe data integer
	temp = arr[pos1]; //masukkan nilai arr[pos1] ke dalam temp
	arr[pos1] = arr [pos2]; //masukkan nilai arr[pos2] ke dalam arr[pos1]
	arr[pos2] = temp; //masukkan nilai temp ke dalam arr[pos2]
}

//function untuk mempartisi array di sekitar elemen pivot.
int partition (int arr[], int low, int high, int pivot) { //mengambil array, indeks rendah, indeks tinggi, dan nilai pivot
int i = low; //deklarasi integer i sebagai index low
int j = low; // deklarasi integer j sebagai index low
//mengulangi array dari indeks rendah ke tinggi
while (i <= high) { 
	if (arr[i] > pivot) { //jika elemen yang ada pada index i lebih besar dari pivot, 'i' di increment
		i++;
	}
	else {  //Jika tidak, elemen pada indeks 'i' ditukar dengan elemen pada indeks j, dan 'i' dan 'j' di increment
	swap (arr, i, j);
	i++;
	j++;
	}
}
return j-1; //mengembalikan posisi pivot setelah dipartisi
}

//function untuk menjalankan quick sort
void quicksort(int arr[], int low, int high) {
//Jika low lebih kecil dari high, menunjukkan bahwa subarray memiliki lebih dari satu elemen, maka dilakukan langkah partisi untuk mencari posisi pivot
	if (low < high) { //berarti ada elemen yang harus diurutkan
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);
		
		quicksort(arr, low, pos-1);
		quicksort(arr, pos+1, high);
	//dipanggil secara rekursif pada subarray kiri (rendah ke pos-1) dan subarray kanan (pos+1 ke tinggi), tidak termasuk pivot itu sendiri
	}
//Rekursi ini berlanjut hingga kasus dasar tercapai, dimana subarray hanya mempunyai satu elemen atau tidak ada elemen
}

int main ()
{
	int n; 
	cout << "Tentukan panjang array = "; //meminta pengguna untuk memasukkan panjang array dan membaca input
	cin>> n;
	
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //kemudian meminta pengguna untuk memasukkan elemen array 
	}
	quicksort(arr, 0, n-1); //memanggil fungsi quicksort untuk mengurutkan array dan menampilkan array yang diurutkan
	cout << "Berikutnya adalah array yang telah di sortir = ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}

// --------------------------------- MERGE SORT -----------------------------------------------
#include <iostream> //file header input - out[ut
using namespace std;

//function untuk menggabungkan dua subarray yang diurutkan menjadi satu
void merge (int arr[], int l, int m, int r) 
{
	int x, y, z;
	int n1 = m - l + 1; //menghitung ukuran subarray kiri L[]
	int n2 = r - m; //menghitung ukuran subarray kanan R[]
	
	int L[n1], R[n2]; //mendeklarasikan dua array sementara untuk menyimpan elemen subarray kiri dan kanan
	for (x = 0; x < n1; x++) //menginisialisasi subarray kiri L[] dengan elemen dari array utama arr[]
        L[x] = arr[l + x]; 
	for (y = 0; y < n2; y++) //menginisialisasi subarray kanan R[] dengan elemen dari array utama arr[]
	    R[y] = arr[m + 1 + y];
	
	//digunakan untuk melacak posisi di subarray kiri L[], subarray kanan R[], dan array gabungan arr[]
	x = 0;
	y = 0;
	z = l;
	
	//membandingkan elemen dari kiri dan kanan, lalu menggabungkannya ke dalam array utama arr[]
	while(x < n1 && y < n2) 
	{
		if (L[x] <= R[y])  //jika benar, elemen dari subarray kiri disalin ke array gabungan arr[]
		{
			arr[z] = L[x];
			x++; //dan x di increment
		}
		else 
		{
			arr[z] = R[y]; //jika salah, elemen dari subarray kanan dimasukkan ke array gabungan arr[]
			y++; //dan y di increment 
		}
		z++; //jika kedua kasus benar, indeks z bertambah untuk berpindah ke posisi berikutnya dalam array gabungan arr[]
	}
	//menyalin elemen yang tersisa dari subarray kiri L[] ke array gabungan arr[]
	while (x < n1) 
	{
		arr[z] = L[x];
		x++;
		z++;
	}
	//menyalin elemen yang tersisa dari subarray kanan R[] ke array gabungan arr[]
	while (y < n2) 
	{
		arr[z] = R[y];
		y++;
		z++;
	}
}

//function untuk mengurutkan array secara rekursif menggunakan pengurutan gabungan
void mergesort(int arr[], int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2; //memastikan array dibagi menjadi dua bagian yang kira-kira sama
		
		mergesort (arr, l, m); //memanggil mergesort secara rekursif untuk bagian kiri array
		mergesort (arr, m + 1, r); //memanggil mergesort secara rekursif untuk bagian kanan array
		
		merge(arr, l, m, r); //menggabungkan dua bagian array yang diurutkan
	}
}

//function untuk menampilkan elemen array
void show(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++) 
		cout << A[i] << " ";
}

int main() {
    int size;
    cout << "Masukan banyak data : ";
    cin >> size; //pengguna memasukkan banyak data yang diinginkan

	for (int i = 0; i < size; i++)
	{
		cout << "\nMasukkan Data Array ke - " << i << " = ";
		cin >> arr[i]; //pengguna memasukkan elemen array
	}

    mergesort(arr, 0, size - 1); //memanggil fungsi mergesort untuk mengurutkan array

    cout << "Hasil : ";
    show(arr, size); //menampilkan elemen array yang diurutkan


    return 0;
}
