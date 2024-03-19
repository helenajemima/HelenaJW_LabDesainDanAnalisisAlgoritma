#include<iostream>
using namespace std;

int main ()
{
    int i, j, arr[100], n, temp, cek, besar, index;

    cout << "Masukkan jumlah elemen : ";
    cin >> n;
    cout << "\nMasukkan nilai elemen : ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nData sebelum sorting: ";
    for(j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    for(i = 0; i < n-1; i++) 
    {
        cek = 0;
        besar = arr[i];
        for(j = i + 1; j < n; j++) 
        {
            if(besar < arr[j]) { 
                besar = arr[j];
                cek++;
                index = j;
            }
        }

        if(cek!=0) {
            temp = arr[i];
            arr[i] = besar;
            arr[index] = temp;
        }

        cout << "Iterasi ke "<<i+1<<" : ";
        for(j = 0; j < n; j++)
            cout << arr[j] << " ";
        cout << endl; 
    }

    cout << "\nData setelah sorting : \n";
    for(i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

