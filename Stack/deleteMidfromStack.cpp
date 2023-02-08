#include<bits/stdc++.h>
using namespace std;   
void printStack(stack<int>st)
{
    stack<int>temp;
    while(!st.empty())
    {
        int e = st.top();
        temp.push(e);
        st.pop();
    } 
    
    while(!temp.empty())
    {
        int e = temp.top();
        cout<<" | "<<e<<" | "<<endl;
        temp.pop();
    } 
}
void deletemidFromstack(stack<int>&st, int mid,int count){
    if(count == mid){
        st.pop();
        return;
    }
    int element = st.top();
    st.pop();
    count++;
    deletemidFromstack(st,mid,count);
    st.push(element);
}                       
int main(){            
    stack<int>st;
    st.push(3);            
    st.push(5);            
    st.push(7);            
    st.push(4);            
    st.push(2);    
    int mid = st.size()/2;
    int count = 0;
    deletemidFromstack(st,mid,count);  
    printStack(st);   // it will print to visualise it not in Normal form but in reverse stack form  
    return 0;          
}                      