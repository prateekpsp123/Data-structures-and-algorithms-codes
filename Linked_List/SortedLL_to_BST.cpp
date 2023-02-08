#include <bits/stdc++.h>
using namespace std;
/*
Sorted Link List to BST
HardAccuracy: 53.24%Submissions: 14K+Points: 8
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with the same value.

Example 1:

Input:
Linked List: 1->2->3->4->5->6->7
Output:
4 2 1 3 6 5 7
Explanation :
The BST formed using elements of the
linked list is,
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7
Hence, preorder traversal of this
tree is 4 2 1 3 6 5 7
*/
class TNode
{
public:
    int data;
    TNode *left;
    TNode *right;
    TNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
class LNode
{
public:
    int data;
    LNode *next;
    LNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
TNode *createBST_Balanced(vector<int> &in, int s, int e)
{
    // Base Case
    if (s > e)
    {
        return NULL;
    }
    // finding the middle element
    int mid = (s + e + 1) / 2;
    int element = in[mid];
    // New Node Creation
    TNode *root = new TNode(element);
    // Create left SubTree
    root->left = createBST_Balanced(in, s, mid - 1);
    // Create Right SubTree
    root->right = createBST_Balanced(in, mid + 1, e);
    // we will return the Tree Now
    return root;
}

TNode *sortedListToBST(LNode *head)
{
    // code here

    vector<int> in;
    int count = 0;
    while (head)
    {
        in.push_back(head->data);
        head = head->next;
        count++;
    }

    int s = 0;
    int e = count - 1;

    return createBST_Balanced(in, s, e);
}

int main()
{

    return 0;
}