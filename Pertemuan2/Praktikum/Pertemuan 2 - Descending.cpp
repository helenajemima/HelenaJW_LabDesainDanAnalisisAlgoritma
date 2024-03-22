#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j<=high - 1; j++){
        if (arr[j] >= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort (arr, low, pi -1);
        quicksort (arr, pi + 1, high);
    }
}

int main(){
    const int size = 5;
    int arr[size];
    
    cout << "Masukkan " << size << " elemen : ";
    for(int i=0; i < size; i++){
        cin >> arr[i];
    }
    cout << endl;
    
    cout<<"Array sebelum diurutkan : ";
	for(int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	} 
    
    quicksort(arr, 0, size - 1);
    
    cout << "\nArray setelah diurutkan : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

//#include <iostream>
//using namespace std;
//
//int part(int arr[], int low, int high){
//	int piv = arr[high];
//	int i = (low - 1);
//	
//	for(int j = low; j <= high - 1; j++){
//		if(arr[j] >= piv){
//			i++;
//			swap(arr[i], arr[j]);
//		}
//	}
//	swap(arr[i+1], arr[high]);
//	return (i+1);
//}
//
//void qs(int arr[], int low, int high){
//	if(low < high){
//		int pi = part(arr, low, high);
//		
//		qs(arr, low, pi-1);
//		qs(arr, pi+1, high);
//	}
//}
//
//int main(){
//	int arr[100], n;
//	
//	cout<<"Masukan 5 elemen : ";
//	for(int i = 0; i < 5; i++){
//		cin>>arr[i];
//	}
//	
//	cout<<"\nArray sebelum diurutkan : ";
//	for(int i = 0; i < 5; i++){
//		cout<<arr[i];
//	}
//	
//	qs(arr, 0, 5-1);
//	
//	cout<<"\nArray setelah diurutkan : ";
//	for(int i = 0; i < 5; i++){
//		cout<<arr[i]<<" ";
//	}
//}

