#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int getCount(int n)
  {
    int ans = 0;
    while(n > 0)
    {
      if(n & 0x01)
      {
        ans++;
      }
      
      n >>= 1;
    }
    
    return ans;
  }
  
public:
  vector<string> readBinaryWatch(int turnedOn) 
  {
    if(turnedOn > 8)
    {
      return {};
    }
    
    vector<pair<int, string>> h(12);
    vector<pair<int, string>> m(60);
    
    for(int i = 0 ; i < 12; ++i)
    {
      pair<int, string> p = {getCount(i), std::to_string(i)};
      h[i] = p;
      
      if(i < 10)
      {
        p.second = "0" + p.second;
      }
      m[i] = p;
    }
    
    for(int i = 12; i < 60; ++i)
    {
      pair<int, string> p = {getCount(i), std::to_string(i)};
      m[i] = p;
    }
    
    vector<string> ans;
    for(int i = 0; i < 12; ++i)
    {
      for(int j = 0; j < 60; ++j)
      {
        if(h[i].first + m[j].first == turnedOn)
        {
          ans.push_back(h[i].second + ":" + m[j].second);
        }
      }
    }
    
    return ans;
  }
};