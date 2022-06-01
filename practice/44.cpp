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
    
    if(pattern[pp] == '*')
    {
      bool skipPattern = doesMatch(str, pattern, sp, pp-1);
      bool skipCharacter = doesMatch(str, pattern, sp-1, pp);
      
      return skipPattern || skipCharacter;
    }
    
    return false;
  }
  
public:
  bool isMatch(string s, string p) 
  {
    return doesMatch(s, p, s.size()-1, p.size()-1);
  }
};