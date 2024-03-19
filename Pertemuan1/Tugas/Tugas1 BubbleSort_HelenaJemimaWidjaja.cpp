#include<iostream>
using namespace std;

int main () 
{
    int i, arr[100], j, n, temp;
    
    cout << "Masukkan banyak array : ";
    cin >> n;
    
    for(i = 0; i < n; i ++) {
        cout << "Masukkan angka ke "<<i+1<<" : "; 
        cin >> arr[i];
        cout << endl;
    }
    
    for(i = 0; i < n; i++) 
    {
        cout << "\nProses sorting\n"; 

        for(j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;

        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    cout << "\nHasil akhir : ";
    for(j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    
    cout << endl;
    return 0;     
}

