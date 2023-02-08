#include <bits/stdc++.h>
using namespace std;
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
Node *createTree(int in[], int post[], int ins, int ine, int &postIndex)
{
    // Base Case
    if (ins > ine || postIndex < 0)
    {
        return NULL;
    }
    int element = post[postIndex];
    Node *root = new Node(element);
    postIndex--;

    if (ins == ine)
    {
        return root;
    }

    int inIndex;
    for (int i = ins; i <= ine; i++)
    {
        if (in[i] == element)
        {
            inIndex = i;
            break;
        }
    }

    root->right = createTree(in, post, inIndex + 1, ine, postIndex);
    root->left = createTree(in, post, ins, inIndex - 1, postIndex);

    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    // Your code here

    int postIndex = n - 1;
    Node *root = createTree(in, post, 0, n - 1, postIndex);

    return root;
}