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
vector<int> mergeSortedArray(vector<int> arr1, vector<int> arr2)
{

    int n = arr1.size();
    int m = arr2.size();
    vector<int> mergeArray(n + m);
    int i = 0;
    int j = 0;
    int mainIndex = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            mergeArray[mainIndex++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            mergeArray[mainIndex++] = arr2[j++];
        }
        else
        {
            mergeArray[mainIndex++] = arr1[i++];
        }
    }

    while (i < n)
    {
        mergeArray[mainIndex++] = arr1[i++];
    }
    while (j < m)
    {
        mergeArray[mainIndex++] = arr2[j++];
    }
    return mergeArray;
}
void inorder(Node *root, vector<int> &temp)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    // Left call                    L
    inorder(root->left, temp);
    // Node pushing                 N
    temp.push_back(root->data);
    // Right Call                   R
    inorder(root->right, temp);
}
int main()
{

    return 0;
}