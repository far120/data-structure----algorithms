#include <bits/stdc++.h>
using namespace std;

void countingSort( vector<int>& arr)
{
    int max = * max_element(arr.begin(), arr.end());

    vector<int> arr_count(max + 1, 0);
    vector<int> arr_output(arr.size());

    for (int i = 0; i < arr.size(); ++i) {
        arr_count[arr[i]] += 1;
    }

    for (int i = 1; i <= max; ++i) {
        arr_count[i] += arr_count[i - 1];
    }

    for (int i = 0; i <  arr.size() ; ++i) {
        arr_output[ arr_count[arr[i]] - 1] = arr[i];
        arr_count[arr[i]]-=1;
    }
    cout << "After sorting:\n";
    for (int i = 0; i < arr.size(); ++i)
//        arr[i] = arr_output[i];
        cout<<arr_output[i]<<" ";
}

int main() {
     vector<int> arr = {4, 2, 2, 8};
     cout << "Before sorting:\n";
    for (int x : arr)
         cout << x << " ";
     cout <<  endl;

    countingSort(arr);

//     cout << "After sorting:\n";
//    for (int x : arr)
//         cout << x << " ";
//     cout <<  endl;

    return 0;
}
