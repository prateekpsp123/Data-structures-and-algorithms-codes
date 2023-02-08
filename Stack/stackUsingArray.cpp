#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int *arr;
    int capacity;
    int top;
    // Constructor
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }
    // PUSH function
    void push(int data)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow reached Maximum Capacity" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    // POP function
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Under flow it is Already Empty" << endl;
        }
        else
        {
            top--;
        }
    }
    // Top function
    void peak()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
    // Size function
    void size()
    {
        cout << top + 1 << endl;
    }
};
int main()
{

    Stack st(5);
    st.push(9);
    st.push(5);
    st.push(3);
    st.push(12);
    st.pop();
    st.peak();
    st.push(3);
    st.push(12);
    st.push(12);
    return 0;
}