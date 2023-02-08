#include <bits/stdc++.h>
using namespace std;
/*
Partition Equal Subset Sum
MediumAccuracy: 30.24%Submissions: 150K+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation  

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
*/
void isSubset(int arr[], int n, int sum, vector<vector<bool>> &dp)
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return 0;
    sum = sum / 2;
    vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1));
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            if (i == 0 && j == 0)
                dp[i][j] = true;

            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    isSubset(arr, N, sum, dp);
    return dp[N][sum];
}
int main()
{

    return 0;
}