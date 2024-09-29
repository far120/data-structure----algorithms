#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr) {
    int s = arr.size();
    for (int g = s / 2; g > 0; g /= 2) {
        for (int i = g; i < s; ++i) {
            int temp = arr[i];
            int j = i;
            while ( j >= g && arr[j - g] > temp) {
                arr[j] = arr[j - g];
                j -= g;
            }
            arr[j] = temp;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {7, 30, 50 , 80 ,10, 8, 9};

    cout << "Array before sorting: \n";
    printArray(arr);

    shellSort(arr);

    cout << "\nArray after sorting: \n";
    printArray(arr);

    return 0;
}


