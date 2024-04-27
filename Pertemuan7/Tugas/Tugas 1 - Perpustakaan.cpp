#include <iostream>
#include <string>

using namespace std;

int binary(string books[], int n, string book) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (books[mid] == book)
            return mid;
        if (books[mid] < book)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    string books[] = {"Bahasa Indonesia", "Bahasa Inggris", "Cerita Pendek", "Ekonomi", "IPS", 
                      "IPA", "Matematika", "Novel", "Seni dan Kesenian", "TIK"};
    int n = sizeof(books) / sizeof(books[0]);
    string book;

    cout << "Pilihlah buku yang ingin anda cari : " << endl
         << "1. Matematika" << endl
         << "2. IPA" << endl
         << "3. Ekonomi" << endl
         << "4. IPS" << endl
         << "5. Seni dan Kesenian" << endl
         << "6. Bahasa Indonesia" << endl
         << "7. Bahasa Inggris" << endl
         << "8. TIK" << endl
         << "9. Cerita Pendek" << endl
         << "10. Novel" << endl;
    cout << "Pilihan : ";

    getline(cin,book);

    int index = binary(books, n, book);

    if (index != -1)
        cout << "Buku " << book << " berada di rak ke-" << index + 1 << "." << endl;
    else
        cout << "Buku " << book << " tidak ditemukan." << endl;

    return 0;
}



