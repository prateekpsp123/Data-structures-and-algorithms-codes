#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *compute(Node *head)
{
    // your code goes here
    int count = 0;
    Node *temp = head;
    vector<int> v;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int n = v.size();
    vector<int> maxi(n);

    int maxm = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > maxm)
        {
            maxm = v[i];
        }
        maxi[i] = maxm;
    }

    temp = head;
    Node *prev = NULL;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data < maxi[i])
        {
            if (temp == head)
            {
                // if the Node is Head Node
                Node *temp1 = head;
                head = head->next;
                temp = head;
                delete temp1;
            }
            else if (temp->next == NULL)
            {
                // If the Node is Last Node
                delete temp;
            }
            else
            {
                // Node which is in Between
                Node *temp2 = temp;
                prev->next = temp->next;
                temp = temp->next;
                temp2->next = NULL;
                delete temp2;
            }
            i++;
        }
        else
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
    }
    return head;
}

int main()
{

    return 0;
}