#include<bits/stdc++.h>
using namespace std;

int isPalindrome(const string& s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}
int getMinPartition(const string& s, int start, int end, vector<vector<int>>& dp)
{
    if((start >= end) || isPalindrome(s, start, end))
    {
        return 0;
    }

    if(dp[start][end] != INT_MIN)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for(int i = start; i < end; ++i)
    {
        int leftCuts = getMinPartition(s, start, i, dp);
        int rightCuts = getMinPartition(s, i+1, end, dp);

        ans = min(ans, 1 + leftCuts + rightCuts);
        dp[start][end] = ans;
    }

    return dp[start][end];
}

int Solution::minCut(string A) 
{
    int l = A.size();
    vector<vector<int>> dp(l, vector<int>(l, INT_MIN));
    return getMinPartition(A, 0, A.size()-1, dp);
}