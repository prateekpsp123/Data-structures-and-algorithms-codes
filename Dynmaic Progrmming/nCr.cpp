#include <bits/stdc++.h>
using namespace std;
/*
nCr
MediumAccuracy: 14.82%Submissions: 203K+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation  
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r 
as input parameters and returns nCr modulo 109+7..

Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)
*/
int nCr(int n, int r)
{
    // code here
    int m = 1e9 + 7;
    int dp[r + 1] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(r, i); j >= 1; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % m;
        }
    }
    return dp[r];
}
int main()
{
    int n;
    int r;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"Enter the value of r: "<<endl;
    cin>>r;
    cout<<"The Value of your"<<n<<"C"<<r<<" is: "<<nCr(n,r)<<endl;
    return 0;
}