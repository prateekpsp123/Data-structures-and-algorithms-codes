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