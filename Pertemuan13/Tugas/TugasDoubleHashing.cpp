#include <iostream>
#include <cmath>   
using namespace std;

int prime_above(int n) {
    if (n <= 1)
        return 2;
    
    n = (n % 2 == 0) ? n + 1 : n + 2; 
    bool found = false;

    while (!found) {
        bool prime = true;
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            found = true;
        else
            n += 2; 
    }
    return n;
}

int prime_below(int n) {
    if (n <= 2)
        return 2;
    
    n = (n % 2 == 0) ? n - 1 : n - 2; 
    bool found = false;

    while (!found && n > 2) {
        bool prime = true;
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            found = true;
        else
            n -= 2; 
    }
    return n;
}

void tambah_double_hashing(int n, int hdt_boundary, int* storage) {
    int hash;
    int hash2 = prime_below(hdt_boundary);
    bool inserted = false;
    int i = 0;
    
    while (!inserted && i < hdt_boundary) {
        hash = ((n % hdt_boundary) + i * ((n) % hash2 + 1)) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
            cout << "Inserted " << n << " at index " << hash << endl;
        } else {
            ++i;
        }
    }

    if (!inserted) {
        cout << "Could not insert " << n << ". Hash table is full." << endl;
    }
}

void display(int table_size, int* storage) {
    cout << "\nHash Table:" << endl;
    for (int i = 0; i < table_size; ++i) {
        cout << "[" << i << "] = " << storage[i] << endl;
    }
}

int main() {
    int hdt_boundary;
    cout << "Enter the size of the hash table: ";
    cin >> hdt_boundary;

    int storage[hdt_boundary] = {0};  

    int num;
    cout << "Enter the number of elements to insert: ";
    cin >> num;

    cout << "Enter " << num << " elements to insert into the hash table:" << endl;
    for (int i = 0; i < num; ++i) {
        int element;
        cout << "Element " << (i + 1) << ": ";
        cin >> element;
        tambah_double_hashing(element, hdt_boundary, storage);
    }

    display(hdt_boundary, storage);
    
    cout << "\nAbove is the Hash Table output result using Double Hashing" << endl;
    cout << "h1(k) = k mod " << hdt_boundary << endl;
    cout << "h2(k) = ( h1(k) + i * (k mod " << prime_below(hdt_boundary) << " + 1) ) mod " << hdt_boundary << endl;

    return 0;
}

