#include <bits/stdc++.h>
using namespace std;
/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
Example 2:

Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4
*/
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverseList(Node *head, Node *end)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != end)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to rotate a linked list.
Node *rotate(Node *head, int k)
{
    // Your code here
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    int count = 1;
    Node *temp = head;

    while (count <= k)
    {
        count++;
        temp = temp->next;
    }

    Node *fhead = reverseList(head, temp);
    Node *shead = reverseList(temp, NULL);

    head->next = shead;

    return reverseList(fhead, NULL);
}

int main()
{

    return 0;
}