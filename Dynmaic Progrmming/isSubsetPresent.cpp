#include<bits/stdc++.h>
using namespace std;   

bool countSubset(int arr[],int n, int sum, vector<vector<bool>>&dp)
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
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
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = true;
    }                   
    for(int j=1; j<=sum; j++)
    {
        dp[0][j] = false;
    }                   
    bool present = countSubset(arr,n,sum,dp); 

    if(present)
    {
        cout<<"Subset is present in the array"<<endl;
    } 
    else
    {
        cout<<"Subset is Not present in the array"<<endl;
    }                 
    return 0;          
} 