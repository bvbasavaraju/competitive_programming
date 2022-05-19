#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::plusOne(vector<int> &A) 
{
    stack<int> st;
    for(int a : A)
    {
        st.push(a);
    }

    int carry = 1;
    stack<int> st2;
    while(!st.empty())
    {
        int d = st.top();
        st.pop();

        d += carry;

        carry = d/10;
        st2.push(d%10);
    }

    if(carry > 0)
    {
        st2.push(carry);
    }

    while(st2.top() == 0)
    {
        st2.pop();
    }

    vector<int> ans;
    while(!st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }

    return ans;
}
