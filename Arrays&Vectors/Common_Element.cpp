#include <bits/stdc++.h>
using namespace std;
/*
Common Elements
EasyAccuracy: 35.98%Submissions: 27K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.

Example:

Input:
n = 5
v1[] = {3, 4, 2, 2, 4}
m = 4
v2[] = {3, 2, 2, 7}
Output:
2 2 3
Explanation:
The common elements in sorted order are {2 2 3}
Your Task:
This is a function problem. You need to complete the function common_element that takes both the lists as parameters and returns a list of common elements.

Constraints:
1 ≤ n, m ≤ 105
1 ≤ Vi ≤ 105
*/
vector<int> Solve(vector<int> first, vector<int> second)
{
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < first.size(); i++)
    {
        mpp[first[i]]++;
    }
    for (int i = 0; i < second.size(); i++)
    {
        if (mpp.find(second[i]) != mpp.end())
        {
            if (mpp[second[i]] > 0)
            {
                ans.push_back(second[i]);
            }
            mpp[second[i]]--;
        }
    }
    return ans;
}

vector<int> common_element(vector<int> v1, vector<int> v2)
{
    // Your code here
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (v1.size() >= v2.size())
    {
        return Solve(v1, v2);
    }
    else
    {
        return Solve(v2, v1);
    }
}
int main()
{

    return 0;
}