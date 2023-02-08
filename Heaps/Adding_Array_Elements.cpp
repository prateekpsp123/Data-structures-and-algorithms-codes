#include <bits/stdc++.h>
using namespace std;
/*
Given an array Arr[] of size N and an integer K, you have to choose the first two minimum elements of the array and erase them, then insert the sum of these two elements in the array until all the elements are greater than or equal to K and find the number of such operations required.

Example 1:

Input:
N = 6, K = 6 
Arr[] = {1, 10, 12, 9, 2, 3}
Output: 2
Explanation: First we add (1 + 2), now the
new list becomes 3 10 12 9 3, then we add
(3 + 3), now the new list becomes 6 10 12 9,
Now all the elements in the list are greater
than 6. Hence the output is 2 i:e 2 operations
are required to do this. 
Example 2:

Input:
N = 4, K = 4
Arr[] = {5, 4, 6, 4}
Output: 0
Explanation: Every element in the given array 
is greater than or equal to K.
*/
int minOperations(int arr[], int n, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n; i++)
    {
        // Pushing
        min_heap.push(arr[i]);
    }
    int top = min_heap.top();
    int ans = 0;
    while (top < k && min_heap.size() >= 2)
    {
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        int sum = a + b;
        min_heap.push(sum);
        ans++;
        top = min_heap.top();
    }
    if (min_heap.top() < k)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 10, 12, 9, 2, 3};
    int n = 6;
    int k =6;
    int ans = minOperations(arr,n,k);
    cout<<"No of Operation required will be: "<<ans<<endl;
    return 0;
}