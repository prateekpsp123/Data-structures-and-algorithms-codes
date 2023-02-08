#include<bits/stdc++.h>
using namespace std;   

int normalReccursion(int i, vector<int>&house)
{
    //Base case
    if(i>=house.size())
    {
        return 0;
    }
    //This depict that he stealing money from this house
    int chori = house[i] + normalReccursion(i+2,house);
    //Not stealing money from this house
    int notchori = 0 + normalReccursion(i+1,house);

    return max(chori,notchori);
}
int reccursionMemoization(int i, vector<int>&house, vector<int>&dp)
{
    //Base case
    if(i>=house.size())
    {
        return 0;
    }
    if(dp[i] != -1)
    {
        return dp[i];
    }
    //This depict that he stealing money from this house
    int chori = house[i] + normalReccursion(i+2,house);
    //Not stealing money from this house
    int notchori = 0 + normalReccursion(i+1,house);

    return dp[i] = max(chori,notchori);
}
int tabulariZation(vector<int>&house, int n, vector<int>&dp)
{
    for(int i=n-1; i>=0; i--)
    {
        int chori = house[i] + dp[i+2];
        int notchori = 0 + dp[i+1];
        dp[i] = max(chori,notchori);
    }
    return dp[0];
}
int main(){       

    vector<int>house{11,5,21,9};
    vector<int>dp(10,0);
    cout<<normalReccursion(0,house)<<endl;
    cout<<tabulariZation(house,4,dp)<<endl;

    return 0;          
}                                         