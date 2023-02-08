#include <bits/stdc++.h>
using namespace std;
/*
Kth Ancestor in a Tree
EasyAccuracy: 35.06%Submissions: 36K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the
function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree.
If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.
Example 1:
Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.

Example 2:

Input:
k=1
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
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
Node *Solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }
    Node *leftAns = Solve(root->left, k, node);
    Node *rightAns = Solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = Solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
}

int main()
{

    return 0;
}