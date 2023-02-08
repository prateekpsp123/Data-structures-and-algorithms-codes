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

Node* reverseLinkedlist(Node* root)
{
    Node* curr = root;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void insertinList(Node* last, int data){
    Node* newNode = new Node(data);
    last->next = newNode;
    last = newNode;
}
void PrintList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(9);
    Node* tail = head;

    insertinList(tail,5);        
    insertinList(tail,8);        
    insertinList(tail,11);        
    insertinList(tail,21);  

    Node* rev = reverseLinkedlist(head);
    PrintList(rev);
    return 0;          
}                      