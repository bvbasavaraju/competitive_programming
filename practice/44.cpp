#include <bits/stdc++.h>
using namespace std;

//Getting time limit exceeded!! - need to optimize!!
class Solution 
{
private:
  bool doesMatch(const string& str, const string& pattern, int sp, int pp)
  {
    if((sp < 0) && (pp < 0))
    {
      return true;
    }
    
    if(sp < 0 && (pp >= 0 && pattern[pp] == '*'))
    {
      return doesMatch(str, pattern, sp, pp-1);
    }
        
    if(sp < 0 || pp < 0)
    {
      return false;
    }
    
    if((str[sp] == pattern[pp]) || (pattern[pp] == '?'))
    {
      return doesMatch(str, pattern, sp-1, pp-1);
    }
    else if(pattern[pp] == '*')
    {
//       bool skipPattern = doesMatch(str, pattern, sp, pp-1);
//       bool skipCharacter = doesMatch(str, pattern, sp-1, pp);
      
//       return skipPattern || skipCharacter;
      return (doesMatch(str, pattern, sp, pp-1) || doesMatch(str, pattern, sp-1, pp));
    }
    
    return false;
  }
  
  bool doesMatch(const string& str, const string& pattern, int sp, int pp, vector<vector<int>>& dp)
  {
    if((sp < 0) && (pp < 0))
    {
      return true;
    }
    
    if(sp >= 0 && pp >= 0 && dp[sp][pp] != -1)
    {
      return dp[sp][pp];
    }
    
    if(sp < 0 && (pp >= 0 && pattern[pp] == '*'))
    {
      return doesMatch(str, pattern, sp, pp-1);
    }
        
    if(sp < 0 || pp < 0)
    {
      return false;
    }
    
    if((str[sp] == pattern[pp]) || (pattern[pp] == '?'))
    {
      dp[sp][pp] = doesMatch(str, pattern, sp-1, pp-1) == true ? 1 : 0 ;
    }
    else if(pattern[pp] == '*')
    {
      bool skipPattern = doesMatch(str, pattern, sp, pp-1);
      bool skipCharacter = doesMatch(str, pattern, sp-1, pp);
      
      dp[sp][pp] = (skipPattern || skipCharacter) ? 1 : 0;
    }
    
    return dp[sp][pp] == 1;
  }
  
public:
  bool isMatch(string s, string p) 
  {
    // return doesMatch(s, p, s.size()-1, p.size()-1);
    
    int sl = s.size();
    int pl = p.size();
    vector<vector<int>> dp(sl, vector<int>(pl, -1));
    return doesMatch(s, p, s.size()-1, p.size()-1, dp);
  }
};