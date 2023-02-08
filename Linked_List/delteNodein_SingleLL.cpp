/*
Delete a Node in Single Linked List
EasyAccuracy: 39.85%Submissions: 111K+Points: 2
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:

Input: 1 -> 3 -> 4
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3.
*/
#include <bits/stdc++.h>
using namespace std;

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

/*You are required to complete below method*/
Node *Solve(Node *head, Node *nodetodel)
{
    Node *prev = NULL;
    Node *temp = head;

    while (temp != nodetodel)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        // If the Node is the Head Node
        Node *temp1 = head;
        head = head->next;
        temp1->next = NULL;
        delete temp1;
    }
    else if (temp->next == NULL)
    {
        // Node is at the Last
        prev->next = NULL;
        delete temp;
    }
    else
    {
        // Node is in between
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
    return head;
}
Node *deleteNode(Node *head, int x)
{
    // Your code here
    int count = 1;
    Node *temp = head;

    while (count != x)
    {
        temp = temp->next;
        count++;
    }

    return Solve(head, temp);
}

int main()
{

    return 0;
}