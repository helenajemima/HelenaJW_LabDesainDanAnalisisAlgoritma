#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

#define TABLE_SIZE 1204

int storage[TABLE_SIZE];
int hdt_boundary;

void tambah_double_hashing(int n)
{
    int hash;
    bool inserted = false;
    int i = 0;
    while (!inserted && i < hdt_boundary)
    {
        hash = (n + i) % hdt_boundary;

        if (storage[hash] == 0)
        {
            storage[hash] = n;
            inserted = true;
        }
        else
        {
            ++i;
        }
    }
}

void cetak()
{
    cout << "\nIsi Tabel Hash :" << endl;
    for (int i = 0; i < hdt_boundary; i++)
    {
        if (storage[i] != 0)
        {
            cout << i << " --> " << storage[i] << endl;
        }
        else
        {
            cout << i << " --> " << "Kosong" << endl;
        }
    }
}

void search(int z)
{
    bool found = false;
    for (int i = 0; i < hdt_boundary; ++i)
    {
        if (storage[i] == z)
        {
            cout << z << " ditemukan dalam tabel hash." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << z << " tidak ditemukan dalam tabel hash." << endl;
    }
}

int main()
{
    int tablesize, n;
    int element;

    srand(static_cast<unsigned>(time(0)));

    cout << "Masukkan ukuran tabel hash : ";
    cin >> tablesize;

    cout << "Masukkan jumlah elemen yang akan disisipkan : ";
    cin >> n;

    hdt_boundary = tablesize;

    cout << "Masukkan " << n << " elemen :" << endl;
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        tambah_double_hashing(element);
    }

    cetak();

    cout << endl << "Masukkan elemen yang ingin dicari dalam tabel hash : ";
    cin >> element;

    search(element);

    return 0;
}

