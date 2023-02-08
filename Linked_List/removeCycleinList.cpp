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

void removeCycleifPresent(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }
    // Cycle is Not Present
    if (fast->next == NULL)
    {
        return;
    }
    else if (fast->next->next == NULL)
    {
        // Cycle is Not Present
        return;
    }
    else if (fast == slow)
    {
        // Cycle is Present -> Now we will remove the Cycle that is Present
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        Node *temp = slow;
        // This Loop will Give the point where the Loops has been Started
        while (temp->next != slow)
        {
            temp = temp->next;
        }
        // Cycle has been Removed
        temp->next = NULL;
    }
}
int main()
{

    return 0;
}