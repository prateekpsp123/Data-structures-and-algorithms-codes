#include <bits/stdc++.h>
using namespace std;
/*
Sum Pair closest to X
EasyAccuracy: 40.64%Submissions: 10K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a sorted array arr[] of size N and a number X, find a pair in array whose sum is closest to X.

Example 1:

Input:
N = 6, X = 54
arr[] = {10, 22, 28, 29, 30, 40}
Output: 22 30
Explanation: As 22 + 30 = 52 is closest to 54.

Example 2:

Input:
N = 5, X = 10
arr[] = {1, 2, 3, 4, 5}
Output: 4 5
Explanation: As 4 + 5 = 9 is closest to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumClosest() which takes
arr[] of size n and x as input parameters and returns a list containing 2 integers denoting the required pair.
If multiple pairs are possible return the largest sum pair.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/
vector<int> sumClosest(vector<int> arr, int x)
{
    // code here
    int a = -1;
    int b = -1;
    int mini = INT_MAX;
    vector<int> ans;
    int s = 0;
    int e = arr.size() - 1;
    while (s < e)
    {
        if (arr[s] + arr[e] == x)
        {
            ans.push_back(arr[s]);
            ans.push_back(arr[e]);
            return ans;
        }
        else if (arr[s] + arr[e] < x)
        {
            int diff1 = abs(x - (arr[s] + arr[e]));
            if (mini > diff1)
            {
                mini = diff1;
                a = arr[s];
                b = arr[e];
            }
            s++;
        }
        else
        {
            int diff2 = abs(x - (arr[s] + arr[e]));
            if (mini > diff2)
            {
                mini = diff2;
                a = arr[s];
                b = arr[e];
            }
            e--;
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
int main()
{

    return 0;
}