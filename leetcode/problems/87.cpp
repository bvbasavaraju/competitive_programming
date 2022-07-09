#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  bool getScrambled(string s1, string s2, unordered_map<string, bool>& cache)
  {
    if(s1 == s2)
    {
      return true;
    }
    
    if(s1.size() <= 1)
    {
      return false;
    }
    
    string merged = s1+"_"+s2;
    if(cache.find(merged) != cache.end())
    {
      return cache[merged];
    }
    
    int l = s1.size();
    for(int i = 1; i < l; ++i)
    {
      int noSwap = getScrambled(s1.substr(0, i), s2.substr(0, i), cache) && getScrambled(s1.substr(i), s2.substr(i), cache);
      int swap = getScrambled(s1.substr(0, i), s2.substr(l-i, i), cache) && getScrambled(s1.substr(i), s2.substr(0,l-i), cache);
      
      if(noSwap || swap)
      {
        cache[merged] = true;
        return cache[merged];
      }      
    }
    
    cache[merged] = false;
    
    return cache[merged];
  }
  
  
public:
  bool isScramble(string s1, string s2) 
  {
    if(s1 == s2)
    {
      return true;
    }
    
    if(s1.size() != s2.size())
    {
      return false;
    }
    
    unordered_map<string, bool> cache;
    return getScrambled(s1, s2, cache);
  }
};