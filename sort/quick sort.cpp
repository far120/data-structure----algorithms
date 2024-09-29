#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h)
{
    int pivot=arr[h];

    int i=l-1;
    for(int j=l;j<=h;j++)
    {
        
        if(arr[j]<pivot)
        {
           
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[h]);
    return (i);
}
void quickSort(int arr[],int l,int h)
{

    if(l<h)
    {
        int pos=partition(arr,l,h);
        quickSort(arr,l,pos-1);
        quickSort(arr,pos+1,h);
    }
}


int main() {
    int arr[]={0,3,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
// Function call
    quickSort(arr,0,n-1);
//Print the sorted array
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

