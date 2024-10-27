#include <iostream>
using namespace std;
template <class t>
class heapsort{
    int left , right , max ;
public:
    void heap(t arr[] , int n ){
        heapstart( arr , n);
        for (int i = n-1; i >= 0 ; --i) {
            swap(arr[i] , arr[0]);
            maxheap(arr , i , 0 );
        }

    }
    void heapstart(t arr[] , int n){
        for (int i = n / 2 - 1; i >= 0; i--) { 
            maxheap(arr, n, i);
        }
        cout<<" max heap ";
        print_A(arr , n );
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
    void print_A(t arr[] , int n ){
        cout<<"[ ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout<<"]"<<endl;
    }
    void print_D(t arr[] , int n ){
        cout<<"[ ";
        for (int i = n-1; i >=0; --i) {
            cout << arr[i] << " ";
        }
        cout<<"]"<<endl;
    }
};

int main() {
    heapsort<int> heap;
    int arr[] = { 10,40,30,5, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heap.heap(arr , n);
    heap.print_A(arr , n );
    heap.print_D(arr , n );
    // string heap sort
    heapsort<string> heapstr;
    string str[] = {"ae", "ab", "ad", "ac", "aa"};
    heapstr.heap(str , n);
    heapstr.print_A(str , n );
    heapstr.print_D(str , n );
    // double heap sort
    heapsort<double> heapd;
    double arrd[] = {9.7 , 8.5 , 10.3 , 1.5 , 5.4};
    heapd.heap(arrd , n);
    heapd.print_A(arrd , n );
    heapd.print_D(arrd , n );

}