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
void reverseUsingReccursion(stack<int>&st){
    //Base Case
    if(st.size() == 0)
    {
        return;
    }
    int element = st.top();
    st.pop();
    reverseUsingReccursion(st);
    insertAtbottom(st,element);
}                         
int main(){
    stack<int>st;
    st.push(3);            
    st.push(5);            
    st.push(7);            
    st.push(4);            
    st.push(2);   
    reverseUsingReccursion(st);  
    printStack(st);   // it will print to visualise it not in Normal form but in reverse stack form  
    return 0;                            
}                      