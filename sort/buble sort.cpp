#include <bits/stdc++.h> //buble sort o(n)
using namespace std;
int main() {
    int arr[5]= {5 , 6 , 10 , 8 ,2 };
    for (int i = 0; i < 5; ++i) {
        int c = 1;
        for (int j = 0; j <4; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                c = 0;
            }
        }
        if (c==1)
        {
            break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout<<arr[i]<<endl;

    }
}