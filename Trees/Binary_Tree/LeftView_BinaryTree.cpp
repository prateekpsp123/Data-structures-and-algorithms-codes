#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //Constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void leftView(Node *root, vector<int> &temp, int level, int &count)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    if (temp[level] == -1)
    {
        count++;
        temp[level] = root->data;
    }

    leftView(root->left, temp, level + 1, count);
    leftView(root->right, temp, level + 1, count);
}
int noOflevel(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + noOflevel(root->left) + noOflevel(root->right);
}
vector<int> leftView(Node *root)
{
    // Your code here
    int n = noOflevel(root);
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = -1;
    }
    int count = 0;
    int level = 0;
    leftView(root, temp, level, count);
    vector<int> ans;
    for (int i = 0; i < count; i++)
    {
        ans.push_back(temp[i]);
    }
    return ans;
}

int main()
{

    return 0;
}