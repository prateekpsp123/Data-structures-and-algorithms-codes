#include <bits/stdc++.h>
using namespace std;
/*
Insert in a Sorted List
EasyAccuracy: 31.37%Submissions: 57K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

Example 1:

Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 19 25 36 47 58 69 80
Example 2:

Input:
LinkedList: 50->100
data: 75
Output: 50 75 100
Your Task:
The task is to complete the function sortedInsert() which should insert the element in sorted Linked List
and return the head of the linked list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
-99999 <= A[i] <= 99999, for each valid i
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

Node *sortedInsert(struct Node *head, int data)
{
    // Code here
    if (head->next == NULL)
    {
        if (data <= head->data)
        {
            Node *ans = new Node(data);
            ans->next = head;
            head = ans;
        }
        else
        {
            Node *ans = new Node(data);
            head->next = ans;
        }
        return head;
    }
    Node *curr = head;
    Node *currNext = head->next;
    if (data <= head->data)
    {
        Node *ans = new Node(data);
        ans->next = head;
        head = ans;
        return head;
    }
    while (currNext != NULL)
    {
        if (data >= curr->data && data <= currNext->data)
        {
            Node *ans = new Node(data);
            curr->next = ans;
            ans->next = currNext;
            return head;
        }
        curr = curr->next;
        currNext = currNext->next;
    }
    if (currNext == NULL)
    {
        Node *ans = new Node(data);
        curr->next = ans;
        return head;
    }
}
int main()
{

    return 0;
}