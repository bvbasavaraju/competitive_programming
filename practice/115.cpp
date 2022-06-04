#include <bits/stdc++.h>
using namespace std;

class Solution 
{
private:
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
public:
  int numDistinct(string s, string t) 
  {
    int sl = s.size();
    int tl = t.size();

    vector<vector<int>> dp(sl+1, vector<int>(tl+1, INT_MIN));
    return getUniqueWays(s, t, 0, 0, dp);
  }
};