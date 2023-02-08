#include <bits/stdc++.h>
using namespace std;
/*
Given an integer N.Create a string using only lowercase characters from a to z that follows the given rules.
When N is even:
Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.

When N is odd:
Case 1: If the sum of digits of N is even, Select (N+1)/2 characters from the beginning
of a-z and (N-1)/2 characters from the ending of a-z.

Case 2: If the sum of digits of N is odd, Select (N-1)/2 characters from the beginning 
of a-z and (N+1)/2 characters from the ending of a-z.

When N is greater than 26,continue repeating the instructions until length of string becomes N.
*/
bool isEven(int N)
{
    int sum = 0;
    while (N != 0)
    {
        int e = N % 10;
        sum += e;
        N = N / 10;
    }
    if (sum % 2 == 0)
    {
        return true;
    }
    return false;
}

string BalancedString(int N)
{
    // code here
    char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string ans = "";
    // case1 - even
    if (N % 2 == 0)
    {
        int front = N / 2;
        int end = N / 2;
        // front front
        for (int i = 0; i < front; i++)
        {
            ans += arr[i];
        }
        // from end
        for (int i = 26 - end; i < 26; i++)
        {
            ans += arr[i];
        }
    }
    else if (N % 2 == 1)
    {
        // case -2 -Odd case
        // digit sum is Even
        if (isEven(N))
        {
            int front = (N - 1) / 2;
            int end = (N + 1) / 2;
            // front front
            for (int i = 0; i < front; i++)
            {
                ans += arr[i];
            }
            // from end
            for (int i = 26 - end - 1; i < 26; i++)
            {
                ans += arr[i];
            }
        }
        else
        {
            // digit sum is Odd
            if (isEven(N))
            {
                int front = (N + 1) / 2;
                int end = (N - 1) / 2;
                // front front
                for (int i = 0; i < front; i++)
                {
                    ans += arr[i];
                }
                // from end
                for (int i = 26 - end - 1; i < 26; i++)
                {
                    ans += arr[i];
                }
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}