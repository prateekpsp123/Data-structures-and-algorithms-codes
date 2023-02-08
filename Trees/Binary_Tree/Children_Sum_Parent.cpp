#include <bits/stdc++.h>
using namespace std;
/*
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.


Example 1:

Input:
     10
    /
  10
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.
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

// Function to check whether all nodes of a tree have the value
// equal to the sum of their child nodes.
int isSumProperty(Node *root)
{
    // Add your code here
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return 1;
    }

    int left = isSumProperty(root->left);
    int right = isSumProperty(root->right);

    int node = 0;
    int a = root->data;
    int b;
    if (root->left == NULL)
    {
        b = 0;
    }
    else
    {
        b = root->left->data;
    }
    int c;
    if (root->right == NULL)
    {
        c = 0;
    }
    else
    {
        c = root->right->data;
    }

    if (a == (b + c))
        node = 1;

    if (left == 1 && right == 1 && node == 1)
        return 1;

    return 0;
}
int main()
{

    return 0;
}