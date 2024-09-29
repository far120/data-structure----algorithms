#include <iostream>
using namespace std;
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024

void bubblesort(int arr[],int x){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Sorted array is: \n";
    for (int i = 0; i < x; i++)
        cout << arr[i] << " ";
    cout << endl;

}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array is: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    bubblesort(arr, n);
  
    return 0;
}



// #include <bits/stdc++.h> //buble sort o(n)
// using namespace std;
// int main() {
//     int arr[5]= {5 , 6 , 10 , 8 ,2 };
//     for (int i = 0; i < 5; ++i) {
//         int c = 1;
//         for (int j = 0; j <4; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//                 c = 0;
//             }
//         }
//         if (c==1)
//         {
//             break;
//         }
//     }
//     for (int i = 0; i < 5; ++i) {
//         cout<<arr[i]<<endl;

//     }
// }

