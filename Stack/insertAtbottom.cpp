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
void insertAtbottom(stack<int>&st,int element){
    //Base Case
    if(st.size()==0){
        st.push(element);
        return;
    }
    //Store the Element for the Future
    int e = st.top();
    st.pop();
    insertAtbottom(st,element);
    // While returning just the Push the element we have stored 
    st.push(e);
}                       
int main(){            
    stack<int>st;
    st.push(3);            
    st.push(5);            
    st.push(7);            
    st.push(4);            
    st.push(2);  
    int element = 11;  
    insertAtbottom(st,element);  
    printStack(st);   // it will print to visualise it not in Normal form but in reverse stack form  
    return 0;          
}