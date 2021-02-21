#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>

using namespace std;

/*
  Q: 10. Regular Expression Matching
*/

class Solution 
{
public:
  bool isMatch(string s, string p) 
  {
    int lp = p.size();
    int ls = s.size();
    
    vector<vector<bool>> dp(ls+1, vector<bool>(lp+1, false));
    dp[0][0] = true;
    
    for(int i = 0; i <= ls; ++i)
    {
      for(int j = 1; j <= lp; ++j)
      {
        if(p[j-1] == '*')
        {
          dp[i][j] = dp[i][j-2] || ((i > 0) && (dp[i-1][j]) && (s[i-1] == p[j-2] || p[j-2] == '.'));
        }
        else
        {
          dp[i][j] = ((i > 0) && (dp[i-1][j-1]) && (s[i-1] == p[j-1] || p[j-1] == '.'));
        }
      }
    }
    
    return dp[ls][lp];
  }
};