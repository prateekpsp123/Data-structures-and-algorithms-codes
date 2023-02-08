#include <bits/stdc++.h>
using namespace std;
/*
Maximum Value
MediumAccuracy: 87.37%Submissions: 103+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a binary tree, find the largest value in each level.


Example 1:

Input:
        1
       / \
      2   3
Output:
1 3
Explanation:
At 0 level, values of nodes are {1}
                 Maximum value is 1
At 1 level, values of nodes are {2,3}
                Maximum value is 3
Example 2:

Input:
        4
       / \
      9   2
     / \   \
    3   5   7
Output:
4 9 7
Explanation:
At 0 level, values of nodes are {4}
                 Maximum value is 4
At 1 level, values of nodes are {9,2}
                 Maximum value is 9
At 2 level, values of nodes are {3,5,7}
                 Maximum value is 7
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
vector<int> maximumValue(Node *node)
{
    // code here
    queue<Node *> q;
    vector<int> ans;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        int maxi = INT_MIN;
        while (size--)
        {
            Node *front = q.front();
            q.pop();
            maxi = max(maxi, front->data);
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        ans.push_back(maxi);
    }
    return ans;
}
int main()
{

    return 0;
}