#include <bits/stdc++.h>
using namespace std;

class Solution 
{
private:  
  bool doesMatch(const string& str, const string& pattern, int sp, int pp, vector<vector<int>>& dp)
  {
    if((sp < 0) && (pp < 0))
    {
      return true;
    }
    
    if(sp >= 0 && pp >= 0 && dp[sp][pp] != -1)
    {
      return dp[sp][pp] == 1;
    }
    
    if(sp < 0 && (pp >= 0 && pattern[pp] == '*'))
    {
      return doesMatch(str, pattern, sp, pp-1, dp);
    }
        
    if(sp < 0 || pp < 0)
    {
      return false;
    }
    
    if((str[sp] == pattern[pp]) || (pattern[pp] == '?'))
    {
      dp[sp][pp] = doesMatch(str, pattern, sp-1, pp-1, dp) == true ? 1 : 0 ;
    }
    else if(pattern[pp] == '*')
    {
      bool skipPattern = doesMatch(str, pattern, sp, pp-1, dp);
      bool skipCharacter = doesMatch(str, pattern, sp-1, pp, dp);
      
      dp[sp][pp] = (skipPattern || skipCharacter) ? 1 : 0;
    }
    
    return dp[sp][pp] == 1;
  }
  
public:
  bool isMatch(string s, string p) 
  {
    int sl = s.size();
    int pl = p.size();
    vector<vector<int>> dp(sl, vector<int>(pl, -1));
    return doesMatch(s, p, s.size()-1, p.size()-1, dp);
    
//     int sl = s.size();
//     int pl = p.size();
    
//     vector<vector<bool>> dp(sl+1, vector<bool>(pl+1, false));
    
//     for(int i = 0; i <= sl; ++i)
//     {
//       for(int j = 0; j <= pl; ++j)
//       {
//         if(i == 0 && j == 0)
//         {
//           dp[i][j] = true;
//           continue;
//         }
        
//         if(i == 0)
//         {
//           dp[i][j] = p[j-1] == '*' ? dp[i][j-1] : false;
//           continue;
//         }
        
//         if(j == 0)
//         {
//           dp[i][j] = false;
//           continue;
//         }
        
//         if(p[j-1] == '?')
//         {
//           dp[i][j] = dp[i-1][j-1];
//         }
//         else if(p[j-1] == '*')
//         {
//           dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
//         }
//         else 
//         {
//           dp[i][j] = (s[i-1] == p[j-1]) ? dp[i-1][j-1] : false;
//         }
//       }
//     }
    
//     return dp[sl][pl];
  }
};