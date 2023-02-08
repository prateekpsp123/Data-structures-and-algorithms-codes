#include <bits/stdc++.h>
using namespace std;
//Implementing Queue Using Two Stacks
class StackQueue{
private:   
  
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

void StackQueue ::push(int x)
{
    // Your Code
    if (s1.empty())
    {
        s1.push(x);
    }
    else
    {
        while (!s1.empty())
        {
            int e = s1.top();
            s2.push(e);
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            int e = s2.top();
            s1.push(e);
            s2.pop();
        }
    }
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    // Your Code
    if (s1.empty())
    {
        return -1;
    }
    else
    {
        int e = s1.top();
        s1.pop();
        return e;
    }
}
int main()
{

    return 0;
}