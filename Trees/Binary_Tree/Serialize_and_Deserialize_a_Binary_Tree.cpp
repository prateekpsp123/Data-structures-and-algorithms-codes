#include <bits/stdc++.h>
using namespace std;
/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
*/
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int preIndex = 0;
Node *createTree(vector<int> in, vector<int> pre, int ins, int ine)
{
    // Base Case
    if (ins > ine)
    {
        return NULL;
    }
    int element = pre[preIndex];
    Node *root = new Node(element);
    preIndex++;

    int inIndex;
    for (int i = ins; i <= ine; i++)
    {
        if (in[i] == element)
        {
            inIndex = i;
            break;
        }
    }

    root->left = createTree(in, pre, ins, inIndex - 1);
    root->right = createTree(in, pre, inIndex + 1, ine);

    return root;
}

void inorder(Node *root, vector<int> &inPre)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inPre);
    inPre.push_back(root->data);
    inorder(root->right, inPre);
}
void preorder(Node *root, vector<int> &inPre)
{
    if (root == NULL)
    {
        return;
    }

    inPre.push_back(root->data);
    inorder(root->left, inPre);
    inorder(root->right, inPre);
}

// Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root)
{
    // Your code here
    vector<int> inPre;
    inorder(root, inPre);
    preorder(root, inPre);
    return inPre;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &A)
{
    // Your code here
    int n = A.size();
    vector<int> in;
    vector<int> pre;

    for (int i = 0; i <= (n / 2) - 1; i++)
    {
        in.push_back(A[i]);
    }

    for (int i = n / 2; i <= n - 1; i++)
    {
        pre.push_back(A[i]);
    }

    return createTree(in, pre, 0, (n / 2) - 1);
}
int main()
{

    return 0;
}