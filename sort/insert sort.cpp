#include <iostream>
using namespace std;
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
void insertionsort(int arr[],int x){
    for (int i = 1; i < x; i++){
        int s = i;
        for (int j = s; j >0; j--){
            if (arr[j] > arr[s]){
                swap(arr[j], arr[s]);
                s--;
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
    int arr[] = {4, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array is: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    insertionsort(arr, n);
  
    return 0;
}