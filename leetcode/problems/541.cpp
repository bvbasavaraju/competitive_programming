#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  string reverseStr(string s, int k) 
  {
    
    int l = s.size();
    if(l < k)
    {
      reverse(s.begin(), s.end());
      return s;
    }
    
    for(int x = 0; x < l; x += 2 * k)
    {
      for(int i = x, j = min(x+k-1, l-1); i < j; ++i, --j)
      {
        swap(s[i], s[j]);
      }
    }
    
    return s;
  }
};