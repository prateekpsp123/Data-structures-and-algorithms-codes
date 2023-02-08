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
int findFirstNode(Node *head)
{
    // your code here
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        // It will go with the speed of 2
        fast = fast->next->next;
        // It will go with the speed of 1
        slow = slow->next;
        // if Both are equals than it means that Loop is present
        if (fast == slow)
        {
            break;
        }
    }

    if (fast->next == NULL || fast->next->next == NULL)
    {
        // No Loop is Present in the Linked List
        return -1;
    }

    fast = head;
    // This Loop will give the Node where the Loop has been started
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // The data of that Node
    int ans = fast->data;
    return ans;
}

int main()
{

    return 0;
}