#include <bits/stdc++.h>
using namespace std;
/*
Connect Nodes at Same Level
MediumAccuracy: 55.78%Submissions: 82K+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a binary tree, connect the nodes that are at same level. You'll be given an addition
nextRight pointer for the same.
Initially, all the nextRight pointers point to garbage values. Your function should set 
these pointers to point next right for each node.

       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL
   
Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
  /    \
 40 ----> 60 ----------> NULL
*/

struct Node
{
    int data;
    Node *left, *right;
    Node *nextRight; // This has garbage value in input trees
};

void Solve(Node *root, vector<vector<Node *>> &store)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<Node *> temp;
        int size = q.size();
        while (size--)
        {
            Node *front = q.front();
            q.pop();
            temp.push_back(front);
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        store.push_back(temp);
    }
}

// Function to connect nodes at same level.
void connect(Node *root)
{
    // Your Code Here
    vector<vector<Node *>> store;
    Solve(root, store);
    int n = store.size();
    for (int i = 0; i < n; i++)
    {
        vector<Node *> temp = store[i];
        int n = temp.size();
        temp[n - 1]->nextRight = NULL;
        for (int i = 0; i < n - 1; i++)
        {
            temp[i]->nextRight = temp[i + 1];
        }
    }
}
int main()
{

    return 0;
}