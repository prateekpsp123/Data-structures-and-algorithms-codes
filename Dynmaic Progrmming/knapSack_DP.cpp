#include <bits/stdc++.h>
using namespace std;

void knapSack(int wt[], int val[], int n, int w, vector<vector<int>> &dp)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               
            }
            else if (wt[n - 1] > j)
            {
                dp[i][j] = dp[i-1][j];
                
            }
        }
    }
}

int main()
{

    int wt[] =  {2, 5, 3, 4, 7, 6};
    int val[] = {4, 3, 2, 7, 5, 8};

    int n = 6;
    int w = 13;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

     knapSack(wt, val, n, w, dp);
    cout << "max_profit is: " <<dp[n][w]<<endl;

    return 0;
}