#include<bits/stdc++.h>
using namespace std;   

int KthSmallest(vector<int>arr, int k)
{
    int n = arr.size();
    priority_queue<int>pq;
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
    int k;            
    cout<<"Enter the value of K: "<<endl;
    cin>>k;
    int ans = KthSmallest(arr,k);
    cout<<"Your "<<k<<"th Smallest elment from the Array is: "<<ans<<endl;
    return 0;          
}                      