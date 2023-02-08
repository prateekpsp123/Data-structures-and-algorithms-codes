#include<bits/stdc++.h>
using namespace std;   

string reverseString(string &str){
    stack<char>st;
    for(int i=0; i<str.size(); i++){
        st.push(str[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        char ch = st.top();
        st.pop();
        ans += ch;
        
    }
    return ans;
}                       
int main(){            
    string str = "Prateek Singh";
   
    cout<<"Your Original String was :"<<endl;
    cout<<str<<endl;   
    string ans = reverseString(str);        
    cout<<"Your Reversed String was :"<<endl;
    cout<<ans<<endl;           
    return 0;          
}                      