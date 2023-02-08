#include<bits/stdc++.h>
using namespace std;   

int KthLargest(vector<int>arr, int k)
{
    int n = arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    int ans = pq.top();
    return ans;
}                       
int main(){            

    vector<int>arr{2,5,7,12,14,23,56,17,19};  
    int n = arr.size();
    int k;            
    cout<<"Enter the value of K: "<<endl;
    cin>>k;
    int ans = KthLargest(arr,k);
    cout<<"Your "<<k<<"th Smallest elment from the Array is: "<<ans<<endl;
    vector<int>arr1{2,5,7,12,14,23,56,17,19};  
    sort(arr1.begin(),arr1.end());
    cout<<"Your "<<k<<"th Smallest elment from the Array is: "<<arr1[n-k]<<endl;
    return 0;          
}                      