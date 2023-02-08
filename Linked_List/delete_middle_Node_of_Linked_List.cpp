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

int lengthNode(Node *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}
Node *deleteMid(Node *head)
{
    // Your Code Here
    if (head == NULL || head->next == NULL)
        return NULL;

    int len = lengthNode(head);
    int mid = len / 2;
    int count = 0;
    Node *middle = head;
    Node *prev = NULL;
    while (count != mid)
    {
        prev = middle;
        middle = middle->next;
        count++;
    }
    if (middle == head)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if (middle->next == NULL)
    {
        prev->next = NULL;
        delete middle;
    }
    else
    {
        prev->next = middle->next;
        middle->next = NULL;
        delete middle;
    }

    return head;
}
int main()
{

    return 0;
}