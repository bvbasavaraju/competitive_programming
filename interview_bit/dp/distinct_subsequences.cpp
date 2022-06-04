#include <bits/stdc++.h>
using namespace std;

int getUniqueWays(const string& a, const string& b, int ap, int bp, vector<vector<int>>& dp)
{
    if(bp == b.size())
    {
        return 1;
    }

    if(ap >= a.size())
    {
        return 0;
    }

    if(dp[ap][bp] != INT_MIN)
    {
        return dp[ap][bp];
    }

    if(a[ap] == b[bp])
    {
        dp[ap][bp] = getUniqueWays(a, b, ap+1, bp+1, dp) + getUniqueWays(a, b, ap+1, bp, dp);
    }
    else
    {
        dp[ap][bp] = getUniqueWays(a, b, ap+1, bp, dp);
    }

    return dp[ap][bp];
}
int Solution::numDistinct(string A, string B) 
{
    int al = A.size();
    int bl = B.size();

    vector<vector<int>> dp(al+1, vector<int>(bl+1, INT_MIN));
    return getUniqueWays(A, B, 0, 0, dp);
}
