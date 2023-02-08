#include<bits/stdc++.h>
using namespace std;    
// Heapify Algorithm - O(log N)
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
int main(){   

    int arr[9] = {-1,54,53,60,34,72,55,85,90};
    // we take the size as total size -1 because we do not consider the first element
    int n = 8;
    // the range of leaf node in the array are always lie from ((n/2)+1) to (n)
    // so all the leaf Nodes are already a heap so will check for the remaining Nodes
    for(int i=n/2; i>0; i--)
    {
        heapify_max(arr,n,i);
    } 
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }     
                  
    return 0;          
}                      