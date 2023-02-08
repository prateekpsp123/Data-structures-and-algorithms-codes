#include <bits/stdc++.h>
using namespace std;

bool valid_Parenthesis(string &str)
{
    stack<char> st;
    for (int i = 0; i < x.size(); i++)
    {

        char e = x[i];
        if (e == '[' || e == '{' || e == '(')
        {
            st.push(x[i]);
        }
        else
        {
            if (st.empty())
                return false;

            else
            {
                char t = st.top();
                if (e == ']' && t == '[')
                {
                    st.pop();
                }
                else if (e == '}' && t == '{')
                {
                    st.pop();
                }
                else if (e == ')' && t == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (st.size() == 0)
        return true;

    return false;
}
int main()
{

    string str = "{{{}}}(())]";
    bool ans = valid_Parenthesis(str);
    if (ans)
    {
        cout << "It is a Valid Parenthesis" << endl;
    }
    else
    {
        cout << "It is Not Valid Parenthesis" << endl;
    }
    return 0;
}