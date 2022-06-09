#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A) 
{
    int l = 0; 
    int h = A.size() - 1;
    
    int ans = 0;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        
        if(m > 0 && m < A.size()-1)
        {
            if(A[m] < A[m+1])
            {
                l = m + 1;
            }
            else
            {
                ans = A[m];
                h = m - 1;
            }
        } 
        else if(m == 0)
        {
            if(A[m] < A[m+1])
            {
                l = m + 1;
            }
            else
            {
                ans = A[m];
                h = m - 1;
            }
        }
        else if(m == A.size()-1)
        {
            if(A[m-1] < A[m])
            {
                return A[m];
            }
            else
            {
                ans = A[m];
                h = m - 1;    
            }
        }
    }
    
    return ans;
}
