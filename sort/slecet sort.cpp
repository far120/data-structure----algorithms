#include <iostream>
using namespace std;
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
void selectionsort(int arr[],int x){
    for (int i = 0; i < x; i++){
        int min_index = i;
        for (int j = i+1; j < x; j++){
            if (arr[min_index] > arr[j]){
                min_index = j;
            }
        }
            swap(arr[i], arr[min_index]);
              
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
    selectionsort(arr, n);
  
    return 0;
}