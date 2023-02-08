#include <bits/stdc++.h>
using namespace std;
/*
We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.
 

Example 1:

Input:
N = 3
asteroids[ ] = {3, 5, -3}
Output: {3, 5}
Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.
Example 2:

Input:
N = 2
asteroids[ ] = {10, -10}
Output: { }
Explanation: The asteroid -10 and 10 collide exploding each other.
Your Task:
You don't need to read input or print anything. Your task is to complete the function asteroidCollision() which takes the array of integers asteroids and N as parameters and returns the state of asteroids after all collisions.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
bool willCollide(int a, int b)
{
    if (a >= 0 && b < 0)
        return true;

    return false;
}

vector<int> asteroidCollision(int N, vector<int> &asteroids)
{
    // code here
    vector<int> ans;
    stack<int> st;
    st.push(asteroids[0]);

    for (int i = 1; i < N; i++)
    {
        int b = asteroids[i];
        if (!st.empty())
        {
            int a = st.top();
            if (willCollide(a, b))
            {
                bool flag = true;
                while (willCollide(a, b))
                {

                    if (a == abs(b))
                    {
                        flag = true;
                        st.pop();
                        break;
                    }
                    else if (a < abs(b))
                    {
                        st.pop();
                        flag = false;
                    }
                    else if (a > abs(b))
                    {
                        flag = true;
                        break;
                    }

                    if (st.empty())
                    {
                        flag = true;
                        st.push(b);
                        break;
                    }

                    a = st.top();
                }
                if (flag == false)
                {
                    st.push(b);
                }
            }
            else
            {
                st.push(b);
            }
        }
        else
        {
            st.push(b);
        }
    }
    if (st.size() == 0)
        return ans;

    while (!st.empty())
    {
        int e = st.top();
        ans.push_back(e);
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}