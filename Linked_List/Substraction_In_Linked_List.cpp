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
// You are required to complete this method
//This function is for checking the length of the list
int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp->data == 0)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
//This function is to reverse the list
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
//This function is to insert the element at the end of the linked list
void insert(Node *&last, int val)
{
    Node *newNode = new Node(val);
    last->next = newNode;
    last = last->next;
}
//This is the main function which will compute the substraction
Node *Solve(Node *first, Node *second)
{
    Node *ans = new Node(-1);
    Node *last = ans;
    //First we will reverse both the list because we have to compute from the back not from the front
    Node *large = reverse(first);
    Node *small = reverse(second);
    //Initially the carry we will take as 0 and according to further we will change it to -1,0
    int carry = 0;
    while (large != NULL && small != NULL)
    {
        if (large->data < small->data)
        {
            large->data += carry;
            large->data += 10;
            int e = large->data - small->data;
            insert(last, e);
            carry = -1;
            large = large->next;
            small = small->next;
        }
        else
        {
            large->data += carry;
            if (large->data < small->data)
            {
                large->data += 10;
                int e = large->data - small->data;
                insert(last, e);
                carry = -1;
                large = large->next;
                small = small->next;
            }
            else
            {
                int e = large->data - small->data;
                insert(last, e);
                carry = 0;
                large = large->next;
                small = small->next;
            }
        }
    }
    while (large != NULL)
    {
        large->data += carry;
        if (large->data < 0)
        {
            large->data = 9;
            carry = -1;
        }
        else
        {
            carry = 0;
        }
        int e = large->data;
        insert(last, e);
        large = large->next;
    }
    
    Node *temp = ans;
    ans = ans->next;
    temp->next = NULL;
    delete temp;

    Node *mans = reverse(ans);
    while (mans->data == 0 && mans != NULL)
    {
        mans = mans->next;
    }
    if (mans == NULL)
    {
        Node *nnode = new Node(0);
        return nnode;
    }
    return mans;
}
Node *subLinkedList(Node *l1, Node *l2)
{
    // Your code here
    // This is for checking weather one of the linked list is Zero and other is Not
    // if it is then the ans will be the other list
    while (l1 != NULL && l1->data == 0)
    {
        l1 = l1->next;
    }
    while (l2 != NULL && l2->data == 0)
    {
        l2 = l2->next;
    }
    //This loop is for removing the trailing zeros because they are of No use
    if (l1 == NULL && l2 != NULL)
    {
        return l2;
    }
    if (l2 == NULL && l1 != NULL)
    {
        return l1;
    }
    // we will take out the length to decide which list is bigger in value as well as size
    int len1 = length(l1);
    int len2 = length(l2);
    // if the l1 list have the bigger size then we will pass it as a list 1(first list)
    //and other one will be the second list
    if (len1 > len2)
    {
        return Solve(l1, l2);
    }
    else if (len1 < len2)
    {
        // if the l2 list have the bigger size then we will pass it as a list 2(first list)
        //and other one will be the second list
        return Solve(l2, l1);
    }
    else
    {
        //This will run when their length are common
        //in this case we will check the first disimilar element which is greater
        Node *temp1 = l1;
        Node *temp2 = l2;
        while (temp1 != NULL && temp2 != NULL && (temp1->data == temp2->data))
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //if there is not a single disimilar element that means both the list are eaual and after the substraction
        //The answer will become Zero
        if (temp1 == NULL && temp2 == NULL)
        {
            Node *ans = new Node(0);
            return ans;
        }
        //This comparision will decide which list is greater and s=according to it it will
        //pass them in the function 
        if (temp1->data > temp2->data)
        {
            return Solve(l1, l2);
        }
        else
        {
            return Solve(l2, l1);
        }
    }
}

int main()
{

    return 0;
}