#include<bits/stdc++.h>
using namespace std;   

int countSubset(int arr[],int n, int sum, vector<vector<int>>&dp)
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}                       
int main(){

    int n;
    cout<<"Enetr the value of n: "<<endl;
    cin>>n;
    int *arr = new int[n];
    cout<<"Eneter the value for the array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the "<<i<<" index Element: "<<endl;
        cin>>arr[i];
    }
    int sum;
    cout<<"Enetr the value of sum: "<<endl;
    cin>>sum;            
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1;
    }                   
    for(int j=1; j<=sum; j++)
    {
        dp[0][j] = 0;
    }                   
    int count = countSubset(arr,n,sum,dp); 
    cout<<"The Number of Subset present for the Sum will be: "<<count<<endl;                  
    return 0;          
}                      