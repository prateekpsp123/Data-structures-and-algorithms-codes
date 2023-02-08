#include <bits/stdc++.h>
using namespace std;

// Function to push all the elements into the stack.
stack<int> _push(int arr[], int n)
{
    // your code here
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(arr[i]);
    }
    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s)
{
    // your code here
    while (!s.empty())
    {
        if (s.size() == 1)
        {
            cout << s.top() << " ";
            break;
        }
        stack<int> temp = s;
        int mini = INT_MAX;
        while (!temp.empty())
        {
            int e = temp.top();
            mini = min(mini, e);
            temp.pop();
        }
        cout << mini << " ";
        s.pop();
    }
}

int main()
{

    return 0;
}