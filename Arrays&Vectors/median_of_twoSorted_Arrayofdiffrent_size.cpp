#include <bits/stdc++.h>
using namespace std;
/*
Median of 2 Sorted Arrays of Different Sizes
HardAccuracy: 28.4%Submissions: 51K+Points: 8
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5
*/
void mergeArray(vector<int> arr1, vector<int> arr2, vector<int> &main)
{
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            main[k++] = arr1[i++];
        }
        else
        {
            main[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        main[k++] = arr1[i++];
    }

    while (j < m)
    {
        main[k++] = arr2[j++];
    }
}
double MedianOfArrays(vector<int> &array1, vector<int> &array2)
{
    // Your code goes here
    int n = array1.size();
    int m = array2.size();
    vector<int> main(m + n);
    mergeArray(array1, array2, main);
    int size = main.size();

    if (size % 2 != 0)
    {
        double ans = double(main[size / 2]);
        return ans;
    }
    else
    {
        double ans = 0;
        double a = double(main[size / 2]);
        double b = double(main[(size / 2) - 1]);
        ans = (a + b) / 2;
        return ans;
    }
}
int main()
{

    return 0;
}