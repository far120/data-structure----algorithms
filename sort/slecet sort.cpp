#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[5] = {5, 6, 10, 8, 2};
    for (int i = 0; i < 5 ; ++i) {
        int m = i;
        for (int j = i + 1; j < 5; ++j) {
            if (arr[j] < arr[m]) {
                m = j;
            }
        }
        swap(arr[i], arr[m]);
    }
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << endl;
    }
}
