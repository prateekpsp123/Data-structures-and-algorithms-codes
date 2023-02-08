#include <bits/stdc++.h>
using namespace std;
/*
Lowest Common Ancestor in a BST
EasyAccuracy: 65.2%Submissions: 101K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root
Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with
values n1 and n2 in the given BST.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= N <= 104
*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
Node *LCA(Node *root, int n1, int n2)
{
    // Your code here
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right == NULL)
        return left;
    else if (left == NULL && right != NULL)
        return right;
    else if (left != NULL && right != NULL)
        return root;
}
int main()
{

    return 0;
}