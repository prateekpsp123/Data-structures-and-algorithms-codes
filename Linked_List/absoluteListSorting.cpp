/*
Absolute List Sorting
EasyAccuracy: 62.03%Submissions: 20K+Points: 2

Given a linked list of N nodes, sorted in ascending order based on the absolute values of its data,i.e.
negative values are considered as positive ones. Sort the linked list in ascending order according to the
actual values, and consider negative numbers as negative and positive numbers as positive.

Example 1:

Input:
List: 1, -2, -3, 4, -5
Output:
List: -5, -3, -2, 1, 4
Explanation:
Actual sorted order of {1, -2, -3, 4, -5}
is {-5, -3, -2, 1, 4}
*/
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
//Function to absolute Sorting the List
Node *sortList(Node *head)
{
    // Your Code Here
    Node *prev = head;
    Node *curr = head->next;
    Node *forward = NULL;
    while (curr != NULL)
    {
        if (curr->data < 0)
        {
            forward = curr->next;
            curr->next = head;
            prev->next = forward;
            head = curr;
            curr = forward;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }
    return head;
}
int main()
{

    return 0;
}
