#include <bits/stdc++.h>
using namespace std;

/*
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
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

int preIndex = 0;
Node *createTree(int in[], int pre[], int ins, int ine)
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
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    Node *root = createTree(in, pre, 0, n - 1);
    return root;
}

int main()
{

    return 0;
}