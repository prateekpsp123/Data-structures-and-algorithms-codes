#include <bits/stdc++.h>
using namespace std;
// For 0 Based Indexing
void heapify_max(vector<int> &arr, int n, int i)
{
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = i;
    // Checking for the Left Child
    if (leftIndex < n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    // Checking for the right Child
    if (rightIndex < n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }
    // If the largest index has changed means there is child node greater than the
    // parent Node
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        // Reccursivly make the tree from the Next index which is now largest
        // to a heap
        heapify_max(arr, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> temp;
    for (auto i : a)
        temp.push_back(i);
    for (auto i : b)
        temp.push_back(i);

    int size = temp.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify_max(temp, size, i);
    }
    return temp;
}

int main()
{
    return 0;
}