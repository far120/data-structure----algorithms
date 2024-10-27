#include <iostream>
using namespace std;
int RecursiveSequentialSearch(int arr[], int n, int value) {
    if (arr[n] == value) {
            return n;
    }
    else if (n == 0) {
        return -1;
    } else {
        return RecursiveSequentialSearch(arr, n - 1, value);
}
}
int main() {
      int arr[] = {10, 67, 49, 32, 56, 25, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    cout << "Enter the value to search for: ";
    cin >> value;
    // value = 32;
    int result = RecursiveSequentialSearch(arr, n , value);
    if (result == -1) {
        cout << "Element "<<value <<" not found" << endl;
    } else {
         cout << "Element "<<value <<" found at index " << result << endl;
    }
    return 0;
}
