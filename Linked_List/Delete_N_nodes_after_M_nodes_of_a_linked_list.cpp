#include <bits/stdc++.h>
using namespace std;
/*
Delete N nodes after M nodes of a linked list
EasyAccuracy: 32.83%Submissions: 42K+Points: 2
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation

Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6

Output:
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains a number of elements in the linked list, and the next M and N respectively space-separated. The last line contains the elements of the linked list.

Output:
The function should not print any output to the stdin/console.

Your Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Constraints:

size of linked list <= 1000

1 <= N + M <= size of linked list
*/
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void linkdelete(struct Node *head, int M, int N)
{
    // Add code here
    M = M - 1;
    Node *temp = head;
    while (temp != NULL)
    {
        int m = M;
        int n = N;
        while (temp != NULL && m--)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *temp2 = temp;
            while (temp2 != NULL && n--)
            {
                temp2 = temp2->next;
            }
            if (temp2 != NULL)
            {
                temp->next = temp2->next;
                temp = temp2->next;
            }
            else
            {
                temp->next = NULL;
            }
        }
        if (temp != NULL && temp->next == NULL)
            break;
    }
}
int main()
{

    return 0;
}