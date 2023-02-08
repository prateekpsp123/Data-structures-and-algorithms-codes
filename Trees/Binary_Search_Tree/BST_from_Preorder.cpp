#include <bits/stdc++.h>
using namespace std;
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
Node *Solve(int arr[], int N, int mini, int maxi, int &i)
{
    // Base Case
    if (i >= N)
    {
        return NULL;
    }
    if (arr[i] < mini || arr[i] > maxi)
    {
        return NULL;
    }
    int element = arr[i];
    i++;
    Node *root = new Node(element);
    // Left call
    root->left = Solve(arr, N, mini, element, i);
    // Right call
    root->right = Solve(arr, N, element, maxi, i);

    return root;
}
Node *canRepresentBST(int arr[], int N)
{
    // code here
    int i = 0;
    Node *root = Solve(arr, N, INT_MIN, INT_MAX, i);
    return root;
}

int main()
{
    
    return 0;
}