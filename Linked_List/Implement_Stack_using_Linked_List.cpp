#include <bits/stdc++.h>
using namespace std;
/*
Implement Stack using Linked List
BasicAccuracy: 53.98%Submissions: 87K+Points: 1
Lamp
Last Day To Save 25% On Top Rated DSA Courses. Explore Offer!

Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
*/
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};
class MyStack
{
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

void MyStack ::push(int x)
{
    // Your Code
    StackNode *newtop = new StackNode(x);
    if (top == NULL)
    {
        top = newtop;
    }
    else
    {
        newtop->next = top;
        top = newtop;
    }
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top == NULL)
        return -1;
    int val = top->data;
    StackNode *temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
    return val;
}

int main()
{

    return 0;
}