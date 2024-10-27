#include <iostream>
#include <algorithm> 
using namespace std;
int RecursiveBinarySearch(int arr[], int low , int high , int value) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return mid;
        else if(arr[mid] < value)
            return RecursiveBinarySearch(arr, mid + 1, high, value);
        else
            return RecursiveBinarySearch(arr, low, mid - 1, value);
    }else {
        return -1; 
    }
}
int main() {
    int arr[] = {10, 67, 49, 32, 56, 25, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    sort(arr, arr + n);
    int value;
    cout << "Enter the value to search for: ";
    cin >> value;
    // value = 67;
    int result = RecursiveBinarySearch(arr, l , n-1 , value);
    if (result == -1) {
        cout << "Element "<<value <<" not found" << endl;
    } else {
         cout << "Element "<<value <<" found at index " << result << endl;
    }
    return 0;
}
