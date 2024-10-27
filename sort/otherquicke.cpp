#include <bits/stdc++.h>
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
int partition(int arr[],int l,int h)
{
    int pivot=arr[l];

    int i=l;
    for(int j=l+1;j<=h;j++)
    {
        
        if(arr[j]<pivot)
        {
           
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[l]);
    // i++;
     for(int x=0;x<=h;x++)
    {
        cout<<arr[x]<<" ";
    }
    cout<<"\n";
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
    int arr[]={40,20,10,80,60,50,7,30,100};
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

