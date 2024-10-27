#include <iostream>
using namespace std;
void hashliner(int arr[], int n) {
    int size = 10;
    int hashtable[size] = {0};  
    for (int i = 0; i < n; i++) {
        int index = arr[i] % size;
        // cout << arr[i]  << " "<< index << endl;
        while (hashtable[index] != 0) {  
            index = (index + 1) % size;  
        }
        hashtable[index] = arr[i];
    }
    cout << "Hash table with liner probing: ";
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << hashtable[i] << " ";
    cout << "]";
    cout << endl;
}

int main() {
    int arr[] = {7,36,18,62};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    hashliner(arr, n);
    return 0;
}
