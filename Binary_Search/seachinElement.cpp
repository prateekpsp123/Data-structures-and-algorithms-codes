#include<bits/stdc++.h>
using namespace std; 
  
//It will Do the Simple Binary Search
int binarySearch(int arr[], int n, int target)
{
    int s =0;
    int e =n-1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        // This Means the Element is Present
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            e = mid-1;
        }
        else if(arr[mid] < target)
        {
            s = mid+1;
        }
    }
    // If the function Reaches here means it does
    // not found the Element in the Array
    return -1;
}
int main(){

    int arr[] = {2,5,8,11,14,19,21,32,45,98,110};
    int target = 19;
    // Give the index of the element if present
    // Time - O(log(N))
    int ans = binarySearch(arr,11,target);
    if(ans==-1)
    {
        cout<<"The Element is Not Present in the Array"<<endl;
    }
    else
    {
        cout<<"Your target element is Present at the Index: "<<ans<<endl;
    }                              
    return 0;          
}                      