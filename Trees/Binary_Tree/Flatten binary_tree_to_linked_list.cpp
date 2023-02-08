#include <bits/stdc++.h>
using namespace std;
/*
Flatten binary tree to linked list
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
*/

class Node
{
    // Visibility
public:
    int data;
    Node *left;
    Node *right;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(Node *root, vector<Node *> &temp)
{
    // Base Case
    if (root == NULL)
        return;
    // Node                      N
    temp.push_back(root);
    // Left recurssive call      L
    preOrder(root->left, temp);
    // Right recurssive call     R
    preOrder(root->right, temp);
}
void flatten(Node *root)
{
    // code here
    vector<Node *> temp;
    // Storing the Nodes in preOrder fashion in temp vector
    preOrder(root, temp);
    // At Every Iteration  We will point the right pointer to The next element Node
    // And Left pointer to the NULL
    for (int i = 0; i < temp.size() - 1; i++)
    {
        Node *tempr = temp[i];
        tempr->right = temp[i + 1];
        tempr->left = NULL;
    }
    // For Last Node Both the Left and Right pointer will be NULL
    Node *tempr = temp[temp.size() - 1];
    tempr->right = NULL;
    tempr->left = NULL;
}
int main()
{

    return 0;
}