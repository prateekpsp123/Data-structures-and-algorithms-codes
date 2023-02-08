#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
            //updating the Pointers
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
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        return mergeList(head1, head2);
    }
    else
    {
        return mergeList(head2, head1);
    }
}
int main()
{

    return 0;
}