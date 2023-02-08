#include<bits/stdc++.h>
using namespace std;   

pair<int,int> Max_and_Second_max(vector<int>arr)
{
    pair<int,int>ans;
    int n = arr.size();
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if(max2 < arr[i] && max1 > arr[i])
        {
            max2 = arr[i];
        }
    }
    ans.first = max1;
    ans.second = max2;

    return ans;
}                       
int main(){            
        vector<int>arr{2,4,6,3,9,11,22,10};
        pair<int,int>ans = Max_and_Second_max(arr);

        cout<<"Maximum element is: "<<ans.first<<endl;               
        cout<<"Second Maximum element is: "<<ans.second<<endl;               
                       
    return 0;          
}                      