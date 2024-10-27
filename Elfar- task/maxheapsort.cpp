#include <iostream>
using namespace std;
template <class t>
class heapsort{
    int left , right , max ;
public:
    void heapstart(t arr[] , int n){
        for (int i = n / 2 - 1; i >= 0; i--) { 
            maxheap(arr, n, i);
        }
        cout<<" max heap ";
        print(arr , n );
    }
    void maxheap(t arr[] , int n , int k){
        left = k*2 +1;
        right = k*2 +2;
        max = k ;
        if(left < n && arr[left]>arr[max])
            max=left ;
        if(right < n && arr[right]>arr[max])
            max=right;

        if(max != k){
            swap(arr[k],arr[max]);
            maxheap(arr,n,max);
        }

    }
    void print(t arr[] , int n){
        cout<<"[ ";
        for (int i = 0; i < n ; ++i) {
            cout << arr[i] << " ";
        }
        cout<<"]"<<endl;
    }
};
int main() {
    heapsort<int> heap;
    int arr[] = { 10,40,30,5, 90  };
    // int arr[] = { 794,716,362,412,937,746,669,984,165,762,958,875,625,428,646,87,123,354,952,379,246,272,461,974,387,682,419,183,140 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heap.heapstart(arr , n);
    // string heap sort
    heapsort<string> heapstr;
    string str[] = {"ae", "ab", "ad", "ac", "aa"};
    heapstr.heapstart(str , n);
    // double heap sort
    heapsort<double> heapd;
    double arrd[] = {9.7 , 8.5 , 10.3 , 1.5 , 5.4};
    heapd.heapstart(arrd , n);
   
}