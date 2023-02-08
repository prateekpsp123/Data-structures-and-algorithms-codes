#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code
    if (q1.empty())
    {
        q1.push(x);
    }
    else
    {
        while (q1.size() != 0)
        {
            int e = q1.front();
            q2.push(e);
            q1.pop();
        }
        q1.push(x);
        while (q2.empty())
        {
            int e = q2.front();
            q1.push(e);
            q2.pop();
        }
    }
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    if (q1.empty())
    {
        return -1;
    }
    else
    {
        int e = q1.front();
        q1.pop();
        return e;
    }
}
int main()
{

    return 0;
}