#include <bits/stdc++.h>
using namespace std;
/*
HardAccuracy: 69.74%Submissions: 10K+Points: 8
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:

Input :
N = 10
Linked List = 1->7->5->3->9->8->10
                      ->2->2->5->NULL
m = 1, n = 8
Output : 2 10 8 9 3 5 7 1 2 5 
Explanation :
The nodes from position 1 to 8 
are reversed, resulting in 
2 10 8 9 3 5 7 1 2 5.

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
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

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

Node *reverseBetween(Node *head, int m, int n)
{
    // code here
    Node *prev = NULL;
    Node *curr = head;
    int count = 1;

    while (count != m)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    Node *end = head;
    Node *endNext = NULL;

    count = 1;
    while (count != n)
    {
        end = end->next;
        count++;
    }
    endNext = end->next;
    if (m == 1)
    {
        Node *newNode = reverseList(head, endNext);
        head->next = endNext;
        return newNode;
    }
    else
    {
        Node *newHead = reverseList(curr, endNext);
        prev->next = newHead;
        curr->next = endNext;
    }

    return head;
}
int main()
{

    return 0;
}