#include<bits/stdc++.h>
using namespace std;   
//This code will work only for the range of the elements if they are smaller than the INT_MAX
//for the range greater than INT_MAX it will not work
vector<int> nextGreaterElementinRange(int arr[], int n)
{
    stack<int>st;
    st.push(INT_MAX);
    vector<int>ans(n);

    for(int i=n-1; i>=0 ; i--)
    {
        int curr = arr[i];
        while(st.top() <= curr)
        {
            st.pop();
        }
        if(st.top() == INT_MAX)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(curr);
    }
    return ans;
}                       
int main(){

    int arr[] = {2,1,4,3};
    int n = 4;
    vector<int>ans = nextGreaterElementinRange(arr,n);
    cout<<"[ ";
    for(auto i:ans)
    {
        cout<<i<<" ";
    } 
    cout<<']';              
    return 0;          
}                      