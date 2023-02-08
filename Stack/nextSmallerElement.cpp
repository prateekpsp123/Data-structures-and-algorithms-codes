#include<bits/stdc++.h>
using namespace std;   

vector<int> nextSmallerElement(int arr[], int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i=n-1; i>=0 ; i--)
    {
        int curr = arr[i];
        while(st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}                       
int main(){

    int arr[] = {2,1,4,3};
    int n = 4;
    vector<int>ans = nextSmallerElement(arr,n);
    cout<<"[ ";
    for(auto i:ans)
    {
        cout<<i<<" ";
    } 
    cout<<']';              
    return 0;          
}                      