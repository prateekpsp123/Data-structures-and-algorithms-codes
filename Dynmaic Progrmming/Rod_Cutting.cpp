#include <bits/stdc++.h>
using namespace std;
/*
Rod Cutting
MediumAccuracy: 60.66%Submissions: 55K+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation:
The maximum obtainable value is
24 by cutting the rod into 8 pieces
of length 1, i.e, 8*3=24.

*/
int Solve(int price[], int length[], int n, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
}

int cutRod(int price[], int n)
{
    // code here
    int len = n;
    vector<vector<int>> dp(n + 1, vector<int>(len + 1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j < len + 1; j++)
    {
        dp[0][j] = 0;
    }
    int *length = new int[len];
    for (int i = 0; i < len; i++)
    {
        length[i] = i + 1;
    }
    int ans = Solve(price, length, n, dp);
    return ans;
}
int main()
{
    
    return 0;
}