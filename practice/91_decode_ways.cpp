#include <bits/stdc++.h>
using namespace std;

class Solution 
{  
public:
  int numDecodings(string s) 
  {
    if(s[0] == '0')
    {
      return 0;
    }
    
    int l = s.size();
    vector<int> countAtPos(l+1, 0);
    countAtPos[0] = 1;
    countAtPos[1] = 1;
    
    for(int i = 1; i < l; ++i)
    {
      int count = 0;
      if(s[i] > '0')
      {
        count = countAtPos[i];
      }
      
      if(s[i-1] == '1')
      {
        count += countAtPos[i-1];
      }
      else if(s[i-1] == '2' && s[i] <= '6')
      {
        count += countAtPos[i-1];
      }
      
      countAtPos[i+1] = count;
    }
    
    return countAtPos[l];
  }
};