
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void Reverse(vector<long long> &ans)
    {
        int i = 0;
        int j = ans.size() - 1;
        while (i <= j)
        {
            swap(ans[i], ans[j]);
            i++;
            j--;
        }
    }

public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> ans;
        stack<long long> s;
        // stack mei -1 daal denge pehle se hi kyunki wo jruri hei
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
                ans.push_back(-1);

            else if (s.size() > 0 && s.top() > arr[i])
            {
                ans.push_back(s.top());
            }
            else if (s.size() > 0 && s.top() <= arr[i])
            {
                while (s.size() > 0 && s.top() <= arr[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                    ans.push_back(-1);

                else
                    ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        Reverse(ans);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}