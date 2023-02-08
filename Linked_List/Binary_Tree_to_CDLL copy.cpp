#include <bits/stdc++.h>
using namespace std;
/*
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked 
List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and 
next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder
of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head
node of the CDLL.

Example 1:

Input:
      1
    /   \
   3     2
Output:
3 1 2 
2 1 3
Explanation: After converting tree to CDLL
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.

Node is as follows:
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
        return;

    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}

// Function to convert binary tree into circular doubly linked list.
Node *bTreeToCList(Node *root)
{
    vector<Node *> in;
    inorder(root, in);
    int n = in.size();
    Node *first = in[0];
    Node *last = in[n - 1];
    first->left = last;
    first->right = in[1];
    last->right = first;
    last->left = in[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        Node *temp = in[i];
        temp->left = in[i - 1];
        temp->right = in[i + 1];
    }

    Node *ans = in[0];
    return ans;
}

int main()
{

    return 0;
}