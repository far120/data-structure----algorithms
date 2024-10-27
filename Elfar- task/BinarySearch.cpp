#include <iostream>
#include <algorithm> 
using namespace std;
int BinarySearch(int arr[], int low , int high , int value) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return mid;
        else if(arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {10, 67, 49, 32, 56, 25, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    sort(arr, arr + n);
    int value;
    cout << "Enter the value to search for: ";
    cin >> value;
    // value = 32;
    int result = BinarySearch(arr, l , n-1 , value);
    if (result == -1) {
        cout << "Element "<<value <<" not found" << endl;
    } else {
         cout << "Element "<<value <<" found at index " << result << endl;
    }
    return 0;
}
