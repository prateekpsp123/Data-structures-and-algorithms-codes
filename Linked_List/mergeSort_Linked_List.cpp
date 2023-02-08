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

Node *mergeList(Node *first, Node *second)
{
    // If the First List have only one Node
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *curr2 = second;
    Node *next1 = curr1->next;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // updating the Pointers
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *midofList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = head;
    Node *temp = head;

    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next->next;
        mid = mid->next;
    }
    return mid;
}

// Function to sort the given linked list using Merge Sort.
Node *mergeSort(Node *head)
{
    // your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = midofList(head);
    Node *right = head;
    Node *left = mid->next;
    mid->next = NULL;

    right = mergeSort(right);
    left = mergeSort(left);

    if (left->data >= right->data)
    {
        return mergeList(right, left);
    }
    else
    {
        return mergeList(left, right);
    }
}

int main()
{

    return 0;
}