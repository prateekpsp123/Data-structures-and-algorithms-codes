#include<bits/stdc++.h>
using namespace std;   

void heapify_max(int *arr, int n, int i)
{
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = i;
    // Checking for the Left Child
    if(leftIndex <=n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    // Checking for the right Child
    if(rightIndex <=n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }
    // If the largest index has changed means there is child node greater than the 
    // parent Node
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        // Reccursivly make the tree from the Next index which is now largest
        // to a heap
        heapify_max(arr,n,largest);
    }
}    

void heapSort(int arr[], int n)
{
    for(int i=n/2; i>0; i--)
    {
        heapify_max(arr,n,i);
    }
    int size = n;
    while(size > 1)
    {
        //step 1: swapping the last and first element
        swap(arr[size],arr[1]);
        //step 2: decrese the size
        size--;
        //stap 3: we will call the heapify func
        heapify_max(arr,size,1);
    }
}
int main(){            
                       
    int arr[] = {-1,34,23,13,45,52,67};
    int n = 6;
    heapSort(arr,n);  
    cout<<"Your Sorted array by the Algorithm Heap sort is: "<<endl; 
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }          
    return 0;          
}                      