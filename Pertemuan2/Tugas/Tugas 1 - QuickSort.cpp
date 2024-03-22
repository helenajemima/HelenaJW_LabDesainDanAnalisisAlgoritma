#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
		
		
		cout << "[";
        for (int i = 0; i < 10; i++) {
        	cout << arr[i] << " ";
    	}
    	cout << "]";
    	cout << endl;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[100];
	
	cout<<"Data yang akan di sort : ";
	for (int i = 0; i < 10; i++) {
        cin>>arr[i];
    }
    
	
    cout << endl << endl;

    cout << "Quick Sort : " << endl;
    quicksort(arr, 0, 10 - 1);

    return 0;
}
