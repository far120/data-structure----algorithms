#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[5]= {9 , 6 , 10 , 8 ,2 };
    for (int i = 1; i < 5; ++i) {
        int s =i ;
        for (int j = s-1; j >=0 ; --j) {
            if (arr[s]<arr[j])
            {
                swap(arr[s],arr[j]);
                s--;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout<<arr[i]<<endl;

    }
}