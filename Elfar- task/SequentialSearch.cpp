#include <iostream>
using namespace std;
int sequentialsearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
int main() {
      int arr[] = {10, 67, 49, 32, 56, 25, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    cout << "Enter the value to search for: ";
    cin >> value;
    // value = 32;
    int result = sequentialsearch(arr, n , value);
    if (result == -1) {
        cout << "Element "<<value <<" not found" << endl;
    } else {
         cout << "Element "<<value <<" found at index " << result << endl;
    }
    return 0;
}
