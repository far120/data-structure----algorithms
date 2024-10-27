#include <iostream>
#include <cmath>
using namespace std;
void hashquadratic(int arr[], int n) {
    int size = 10;
    int x =0;
    int hashtable[size] = {0};  
    for (int i = 0; i < n; i++) {
        int index = arr[i] % size;
        // cout << arr[i]  << " "<< index << endl;
        while (hashtable[index] != 0) { 
             x++;
            int p = pow(x , 2);
            index =(index + p ) % size;  
        }
        hashtable[index] = arr[i];
    }
    cout << "Hash table with quadratic probing: ";
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << hashtable[i] << " ";
    cout << "]";
    cout << endl;
}

int main() {
    int arr[] = {2, 12, 22, 32, 42, 52  };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    hashquadratic(arr, n);
    return 0;
}
