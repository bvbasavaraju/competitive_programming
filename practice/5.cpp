#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:  
  pair<int, int> getLongestPalindome(const string& s, int l, int r)
  {
    pair<int, int> ans = {0, 0};
    while(l >= 0 && r < s.size() && s[l] == s[r])
    {
      ans = {l, r};
      l--;
      r++;
    }
    
    return ans;
  }
  
public:
  string longestPalindrome(string s) 
  {
    int l = s.size();
    
    pair<int, int> maxi = {0, 0};
    for(int i = 0; i < l; ++i)
    {
      pair<int, int> p1 = getLongestPalindome(s, i, i);
      pair<int, int> p2 = getLongestPalindome(s, i, i+1);
            
      if((p1.second - p1.first) >= p2.second - p2.first)
      {
        if((p1.second - p1.first) > (maxi.second - maxi.first))
        {
          maxi = p1; 
        }
      }
      else
      {
        if((p2.second - p2.first) > (maxi.second - maxi.first))
        {
          maxi = p2; 
        }
      }
    }
    
    
    return s.substr(maxi.first, maxi.second - maxi.first + 1);
  }
};