#include <bits/stdc++.h>
using namespace std;
/*
Vertical sum
EasyAccuracy: 64.76%Submissions: 24K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation  

Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through
different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
Your Task:
You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter
and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of nodes<=1000
*/
struct Node
{
    int data;
    Node *left, *right;
};

vector<int> verticalSum(Node *root)
{
    // add code here.
    map<int, vector<int>> mpp;
    queue<pair<int, Node *>> q;
    vector<int> ans;
    if (root == NULL)
        return ans;

    q.push(make_pair(0, root));
    while (!q.empty())
    {
        pair<int, Node *> frontNode = q.front();
        q.pop();
        Node *temp = frontNode.second;
        int hd = frontNode.first;
        mpp[hd].push_back(temp->data);
        if (temp->left)
            q.push(make_pair(hd - 1, temp->left));
        if (temp->right)
            q.push(make_pair(hd + 1, temp->right));
    }
    for (auto i : mpp)
    {
        int sum = 0;
        vector<int> temp(i.second.size());
        temp = i.second;
        for (int i = 0; i < temp.size(); i++)
        {
            sum += temp[i];
        }
        ans.push_back(sum);
    }
    return ans;
}
int main()
{

    return 0;
}