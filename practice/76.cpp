#include<bits/stdc++.h>
using namespace std;

class Solution 
{  
private:  
  bool hasTarget(vector<int>& tFreq, vector<int>& sFreq)
  {
    for(int i = 0; i < 128; ++i)
    {
      if(tFreq[i] > sFreq[i])
      {
        return false;
      }
    }
    
    return true;
  }
public:
  string minWindow(string s, string t) 
  {
    int sl = s.size();
    int tl = t.size();
    
    if(tl > sl)
    {
      return "";
    }
    
    vector<int> sFreq(128, 0);
    vector<int> tFreq(128, 0);
    for(char ch : t)
    {
      tFreq[ch]++;
    }
    
    for(int i = 0; i < tl; ++i)
    {
      sFreq[s[i]]++;
    }
    
    if(sFreq == tFreq)
    {
      return s.substr(0, tl);
    }
    
    int i = tl;
    pair<int, int> p = {0, 0};
    pair<int, int> minPair{-1, -1};
    while(i < sl)
    {
      sFreq[s[i]]++;
      while(hasTarget(tFreq, sFreq))
      {
        p.second = i;
        if(minPair.first == -1 || (minPair.second - minPair.first) > (p.second- p.first))
        {
          minPair = p;
        }
        sFreq[s[p.first++]]--;
      }
      
      i++;
    }
    
    return minPair.first == -1 ? "" : s.substr(minPair.first, (minPair.second - minPair.first+1));
  }
};