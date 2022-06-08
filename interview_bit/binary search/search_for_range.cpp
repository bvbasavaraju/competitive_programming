#include<bits/stdc++.h>

using namespace std;

int getPos(const vector<int>& A, int val, bool first)
{
    int l = 0;
    int h = A.size()-1;

    int ans = -1;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        if(A[m] == val)
        {
            ans = m;
            if(first)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        else if(A[m] < val)
        {
            l = m+1;
        }
        else
        {
            h = m-1;
        }
    }

    return ans;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int first = getPos(A, B, true);
    if(first < 0)
    {
        return {first, first};
    }

    return {first, getPos(A, B, false)};
}
