#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
}; 

void insertAtend(Node *&last, int data)
{

    struct Node *temp = new Node(data);

    last->next = temp;
    last = last->next;
}
Node *reverseList_1(Node *head)
{

    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
// Function to add two numbers represented by linked list.
Node *addTwoLists(struct Node *first, Node *second)
{
    // code here
    struct Node *head_1 = reverseList_1(first);
    struct Node *head_2 = reverseList_1(second);

    struct Node *head = new Node(-1);
    struct Node *last = head;

    int carry = 0;

    while (head_1 != NULL && head_2 != NULL)
    {

        int sum = head_1->data + head_2->data + carry;
        int number = sum % 10;
        carry = sum / 10;
        insertAtend(last, number);
        head_1 = head_1->next;
        head_2 = head_2->next;
    }

    while (head_1 != NULL)
    {

        int sum = head_1->data + carry;
        int number = sum % 10;
        carry = sum / 10;
        insertAtend(last, number);
        head_1 = head_1->next;
    }

    while (head_2 != NULL)
    {

        int sum = head_2->data + carry;
        int number = sum % 10;
        carry = sum / 10;
        insertAtend(last, number);
        head_2 = head_2->next;
    }

    if (carry != 0)
    {
        insertAtend(last, carry);
    }

    struct Node *temp3 = head;
    head = head->next;

    temp3->next = NULL;
    delete temp3;

    struct Node *ans = reverseList_1(head);
    return ans;
}
int main()
{

    return 0;
}