#include <iostream>
using namespace std;
template <class t>
class heapsort{
    int left , right , min ;
public:
    void heap(t arr[] , int n ){
        heapstart( arr , n);
        for (int i = n-1; i >= 0 ; --i) {
            swap(arr[i] , arr[0]);
            minheap(arr , i , 0 );
        }

    }
    void heapstart(t arr[] , int n){
        for (int i = n / 2 - 1; i >= 0; i--) { /// parent you start from him
            minheap(arr, n, i);
        }
        cout<<" min heap ";
        print_A(arr , n );
    }
    void minheap(t arr[] , int n , int k){
        left = k*2 +1;
        right = k*2 +2;
        min = k ;
        if(left < n && arr[left]<arr[min])
            min=left ;
        if(right < n && arr[right]<arr[min])
            min=right;

        if(min != k){
            swap(arr[k],arr[min]);
            minheap(arr,n,min);
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
