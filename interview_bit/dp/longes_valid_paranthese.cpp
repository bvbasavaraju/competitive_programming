#include<bits/stdc++.h>
using namespace std;

int Solution::longestValidParentheses(string A) 
{
    int ans = 0;
    
    int l = A.size();
    int openCount = 0;
    int closeCount = 0;
    for(int i = 0; i < l; ++i)
    {
        if(A[i] == '(')
        {
            openCount++;
        }
        if(A[i] == ')')
        {
            closeCount++;
        }

        if(closeCount > openCount)
        {
            openCount = 0;
            closeCount = 0;
        }
        else if(openCount == closeCount)
        {
            ans = max(ans, openCount+closeCount);
        }
    }

    openCount = 0;
    closeCount = 0;
    for(int i = l-1; i >= 0; --i)
    {
        if(A[i] == '(')
        {
            openCount++;
        }
        if(A[i] == ')')
        {
            closeCount++;
        }

        if(openCount > closeCount)
        {
            openCount = 0;
            closeCount = 0;
        }
        else if(openCount == closeCount)
        {
            ans = max(ans, openCount+closeCount);
        }
    }

    return ans;
}
