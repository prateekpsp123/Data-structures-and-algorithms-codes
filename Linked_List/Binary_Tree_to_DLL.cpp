#include <bits/stdc++.h>
using namespace std;
/*
Binary Tree to DLL
HardAccuracy: 53.36%Submissions: 108K+Points: 8
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!  

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: H is the height of the tree and this space is used implicitly for the recursion stack.
 

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
*/
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<Node *> &in)
{
    if (root == NULL)
    {
        return;
    }
    // left traversal
    inorder(root->left, in);
    // Node pushing
    in.push_back(root);
    // right traversal
    inorder(root->right, in);
}

// Function to convert binary tree to doubly linked list and return it.
Node *bToDLL(Node *root)
{
    // your code here
    if (root->left == NULL && root->right == NULL)
        return root;

    vector<Node *> in;
    inorder(root, in);
    int n = in.size();
    Node *first = in[0];
    first->left = NULL;
    first->right = in[1];

    Node *last = in[n - 1];
    last->right = NULL;
    last->left = in[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        Node *curr = in[i];
        curr->left = in[i - 1];
        curr->right = in[i + 1];
    }

    return first;
}
int main()
{

    return 0;
}