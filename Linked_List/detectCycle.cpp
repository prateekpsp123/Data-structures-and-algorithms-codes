#include<bits/stdc++.h>
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
bool detectCycle(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;
        }
    }
    if(fast->next == NULL)
    {
        return false;
    }
    if(fast->next->next == NULL)
    {
        return false;
    }
    return true;
}                      
int main(){            
                       
                       
    return 0;          
}                      