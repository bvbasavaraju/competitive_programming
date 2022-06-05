#include<bits/stdc++.h>
using namespace std;

int Solution::jump(vector<int> &A) 
{
    int l = A.size();
    vector<int> jumps(l, INT_MAX);

    int maxReach = INT_MIN;
    jumps[0] = 0;
    maxReach = 0;
    int jumpsCalculatedTill = 0;
    for(int i = 0; i < l; ++i)
    {
        if(i > maxReach)
        {
            return -1;
        }

        maxReach = max(maxReach, i+A[i]);
        
        int maxIndex = min(i+A[i], l-1);
        jumps[maxIndex] = min(jumps[maxIndex], 1+jumps[i]);

        for(int j = jumpsCalculatedTill+1; j < maxIndex; ++j)
        {
            jumps[j] = min(jumps[j], 1+jumps[i]);
        }
        jumpsCalculatedTill = max(jumpsCalculatedTill, maxIndex);
    }

    return jumps[l-1];
}

