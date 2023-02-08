#include<bits/stdc++.h>
using namespace std;   
/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
*/
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
void insert(Node* &lastNext, Node* &bottomNext, int val)
{
    Node* newNode = new Node(val);
    lastNext->next = newNode;
    lastNext->bottom = newNode;
    lastNext = newNode;
    bottomNext = newNode;
    
}
Node *flatten(Node *root)
{
   // Your code here
   vector<int>store;
   Node* temp = root;
   
   while(temp != NULL)
   {
       Node* temp2 = temp;
       while(temp2 != NULL)
       {
           store.push_back(temp2->data);
           temp2 = temp2->bottom;
       }
       temp = temp->next;
   }
   sort(store.begin(),store.end());
   Node* ans = new Node(-1);
   Node* last = ans;
   Node* blast = ans;
   int n = store.size();
   
   for(int i=0; i<n; i++)
   {
       insert(last,blast,store[i]);
   }
   return ans->next;
}

int main(){            
                       
                       
    return 0;          
}                      