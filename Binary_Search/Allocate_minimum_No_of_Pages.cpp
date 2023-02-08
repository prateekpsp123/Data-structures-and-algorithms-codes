#include <bits/stdc++.h>
using namespace std;

/*
Allocate minimum number of Pages
Hard    Accuracy: 35.51%    Submissions: 106K+    Points: 8
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

You are given N number of books. Every ith book has Ai number of pages.
You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so.
In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations,
the task is to find that particular permutation in which the maximum number of pages allocated to a student
is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in
following ways:{12} and {34, 67, 90}
Maximum Pages = 191{12, 34} and {67, 90}
Maximum Pages = 157{12, 34, 67} and {90}
Maximum Pages = 113. Therefore, the minimum
of these cases is 113, which is selected
as the output.
*/
bool isPossible(int A[], int N, int M, int mid)
{
    int Studentcount = 1;
    int Pagesum = 0;

    for (int i = 0; i < N; i++)
    {
        if (Pagesum + A[i] <= mid)
        {
            Pagesum += A[i];
        }
        else
        {
            Studentcount++;
            if (Studentcount > M || A[i] > mid)
            {
                return false;
            }
            Pagesum = A[i];
        }
    }
    return true;
}
// Function to find minimum number of pages.
int findPages(int A[], int N, int M)
{
    // code here
    int s = 0;
    int e = 0;
    for (int i = 0; i < N; i++)
    {
        e += A[i];
    }
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(A, N, M, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int N = 4;
    int A[] = {12, 34, 67, 90};
    int M = 2;
    int ans = findPages(A, N, M);
    cout << "The Minimum Number of Pages in the Allocated from the Maximum Allocatiom : " << ans << endl;

    return 0;
}