#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[], int val[], int n, int w,vector<vector<int>>&dp){

    //Base case
    if(n==0 || w ==0){
        return 0;
    }

    if(dp[n][w] != -1){

        return dp[n][w];
    }

    if(wt[n-1] <= w){
        dp[n][w] = max(val[n-1] + knapSack(wt,val,n-1,w-wt[n-1],dp), knapSack(wt,val,n-1,w,dp));
        return dp[n][w];
    }
    else{
        dp[n][w] = knapSack(wt,val,n-1,w,dp);
        return dp[n][w];
    }
}

int main(){

    int wt[] =  {2, 5, 3, 4, 7, 6};
    int val[] = {4, 3, 2, 7, 5, 8};
    
    int n = 6;
    int w = 13;

    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));

    int maxProfit = knapSack(wt,val,n,w,dp);
    cout<<"The maximum profit will be :"<<maxProfit<<endl;

    return 0;
}