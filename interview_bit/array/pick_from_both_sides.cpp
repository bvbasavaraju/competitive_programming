/*
  Q: https://www.interviewbit.com/problems/pick-from-both-sides/
*/

#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B) 
{
    int l = A.size();
    
    int sum = 0;
    int ans = INT_MIN;

    for(int i = l-B; i < l; ++i)
    {
        sum += A[i];
    }

    ans = max(ans, sum);
    for(int i = 0; i < B; ++i)
    {
        sum += A[i] - A[l-B-i];
        ans = max(ans, sum);
    }

    return ans;
}
